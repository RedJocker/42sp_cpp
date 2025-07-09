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
	exit 1;
    fi
}

command="$program"
expected='vec<int>:
{ 1 4 3 2 } found: 2 atPosition: 3
{ 1 2 3 2 } found: 2 atPosition: 1
{ 10 20 30 40 10 20 } notFound: 2
deque<int>:
{ 10 20 30 40 10 20 } found: 20 atPosition: 1
{ 10 20 30 40 10 20 } found: 40 atPosition: 3
set<int>:
{ -42 0 42 } notFound: -100
{ -42 0 42 } found: -42 atPosition: 0
{ -42 0 42 } found: 0 atPosition: 1
{ -42 0 42 } found: 42 atPosition: 2'
run_test_command
