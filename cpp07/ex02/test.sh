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
expected="arr0.size(): 0
out of range access on arr0

arr1.size(): 10
arr1[0] before setting: 0
arr1[0] after setting: 100
arr1[9]: 0

arrStr.size(): 5
arrStr[2] before setting: ''
arrStr[2] after setting: 'some string value'

testing copy constructor:
arrOriginal[i]: 10
arrOriginal[i]: 20
arrOriginal[i]: 30
arrOriginal[i]: 40
arrOriginal[i]: 50
arrOriginal[i]: 60
arrOriginal[i]: 70
arrOriginal[i]: 80
arrOriginal[i]: 90
arrOriginal[i]: 100
before modify copy:
arrCopy[i]: 10
arrCopy[i]: 20
arrCopy[i]: 30
arrCopy[i]: 40
arrCopy[i]: 50
arrCopy[i]: 60
arrCopy[i]: 70
arrCopy[i]: 80
arrCopy[i]: 90
arrCopy[i]: 100
after modify copy:
arrCopy[i]: 1
arrCopy[i]: 2
arrCopy[i]: 3
arrCopy[i]: 4
arrCopy[i]: 5
arrCopy[i]: 6
arrCopy[i]: 7
arrCopy[i]: 8
arrCopy[i]: 9
arrCopy[i]: 10
arrOriginal[i]: 10
arrOriginal[i]: 20
arrOriginal[i]: 30
arrOriginal[i]: 40
arrOriginal[i]: 50
arrOriginal[i]: 60
arrOriginal[i]: 70
arrOriginal[i]: 80
arrOriginal[i]: 90
arrOriginal[i]: 100

testing assignment operator:
arrOriginal[i]: 10
arrOriginal[i]: 20
arrOriginal[i]: 30
arrCopy.size(), before assignment: 0
arrCopy.size(), after assignment: 3
before modify copy:
arrCopy[i]: 10
arrCopy[i]: 20
arrCopy[i]: 30
after modify copy:
arrCopy[i]: 1
arrCopy[i]: 2
arrCopy[i]: 3
arrOriginal[i]: 10
arrOriginal[i]: 20
arrOriginal[i]: 30"
run_test_command
