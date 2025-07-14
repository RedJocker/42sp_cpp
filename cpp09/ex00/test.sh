#!/bin/bash

program="./$(grep 'NAME :=' ./Makefile | cut -d'=' -f2 | xargs)"

make
build_status="$?"

if (( build_status != 0 )); then
    exit $build_status;
fi

if ! [ -x $program ]; then
    echo "missing $program executable, check if right NAME on Makefile"
    exit 1;
fi

run_test_command() {
    actual=$($command)
    status="$?"
    if [[ "$actual" != "$expected" ]]; then
	echo "[BAD] test: $command ";
	echo "actual:"
	echo "$actual";
	echo ""
	echo "expected:"
	echo "$expected"
	echo ""
	echo "input file:"
	cat "$TMPFILE"
	exit 42;
    elif (( status != expected_status )); then
	"[BAD] test: $command ";
	echo "actual status: $status"
	echo "expected status: $expected_status"
	exit $status
    else
	echo "[GOOD] test: $command ";
    fi
}

command="$program"
expected="Usage: $program fileName"
expected_status='11'
run_test_command

command="$program does_not_exist"
expected="Could not open does_not_exist"
expected_status='22'
run_test_command

TMPFILE=$(mktemp)
echo 'date | value
2011-01-03 | 3
' > "$TMPFILE"
command="$program $TMPFILE"
expected='2011-01-03 => 3 = 0.9'
expected_status='0'
run_test_command

TMPFILE=$(mktemp)
echo 'date | value
2012-01-11 | -1
' > "$TMPFILE"
command="$program $TMPFILE"
expected='Error: not a positive number.'
expected_status='0'
run_test_command

TMPFILE=$(mktemp)
echo 'date | value
2001-42-42
' > "$TMPFILE"
command="$program $TMPFILE"
expected='Error: bad input => 2001-42-42'
expected_status='0'
run_test_command

TMPFILE=$(mktemp)
echo 'date | value
2012-01-11 | 2147483648
' > "$TMPFILE"
command="$program $TMPFILE"
expected='Error: too large a number.'
expected_status='0'
run_test_command

TMPFILE=$(mktemp)
echo 'date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
' > "$TMPFILE"
command="$program $TMPFILE"
expected='2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.'
expected_status='0'
run_test_command

TMPFILE=$(mktemp)
echo 'date | value
2000-01-03 | 3
abc | 3
2011-30-03 | 3
2011-01-32 | 3
2011-02-11 , 3
2011-02-11 | abc
2011-02-11 | 30.3abc
2011-02-11 | 30.3
' > "$TMPFILE"
command="$program $TMPFILE"
expected='Error: no exchange rate at this early date 2000-01-03
Error: bad input => abc | 3
Error: bad input => 2011-30-03 | 3
Error: bad input => 2011-01-32 | 3
Error: bad input => 2011-02-11 , 3
Error: bad input => 2011-02-11 | abc
Error: bad input => 2011-02-11 | 30.3abc
2011-02-11 => 30.3 = 29.391'
expected_status='0'
run_test_command


