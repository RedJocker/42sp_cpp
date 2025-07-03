#!/bin/bash

program="./serialize"

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
    if [ "$actual" = "$expected" ]; then
	echo "[GOOD] test: $command ";
    else
	echo "[BAD] test: $command ";
	echo "actual:"
	echo "$actual";
	echo ""
	echo "expected:"
	echo "$expected"
    fi
}

command="$program"
expected='Usage: converter strToConvert'
run_test_command
#
command="$program 1 2"
expected='Usage: converter strToConvert'
run_test_command
#
command="$program 1"
expected=$(cat <<EOF
char: Non displayable
int: 1
float: 1.0f
double: 1.0
EOF
)
run_test_command
#
command="$program 1f"
expected=$(cat <<EOF
char: Non displayable
int: 1
float: 1.0f
double: 1.0
EOF
)
run_test_command
