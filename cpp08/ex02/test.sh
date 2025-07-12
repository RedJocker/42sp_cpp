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
    if [[ "$actual" == "$expected" ]]; then
	echo "[GOOD] test: $command ";
    else
	echo "[BAD] test: $command ";
	echo "actual:"
	echo "$actual";
	echo ""
	echo "expected:"
	echo "$expected"
	exit 42;
    fi
}

command="$program"
expected='17
1
5
3
5
737
0

0
737
5
3
5

5
3
5
737
0

5
3
5
737
0

0
737
5
3
5

0
737
5
3
5'
run_test_command
