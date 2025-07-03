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
    if [[ "$actual" =~ $expected ]]; then
	echo "[GOOD] test: $command ";
    else
	echo "[BAD] test: $command ";
	echo "actual:"
	echo "$actual";
	echo ""
	echo "expected:"
	echo "$expected"
	exit 1;
    fi
}

command="$program"
expected="some data
0x[0-9a-fA-F]+
0x[0-9a-fA-F]+
some data"
run_test_command

# 0x[0-9a-fA-F]+
# 0x[0-9a-fA-F]+
