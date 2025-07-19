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
expected="Usage: ./RPN (list of operands and operators using polish postfix notation)
ex: ./RPN  8 9 * 9 - 9 - 9 - 4 - 1 +"
expected_status='11'
run_test_command

