#!/bin/bash

program="./templates"

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
    if [[ "$actual" == "$expected" ]]; then
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
expected="i: 1
i: 2
i: 3
i: 4
i: 5

i: 1
i: 2
i: 3

str: hello
str: mate

generic: 1
generic: 2
generic: 3
generic: 4
generic: 5

generic: hello
generic: mate"
run_test_command
