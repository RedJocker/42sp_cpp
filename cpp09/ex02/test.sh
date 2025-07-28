#!/bin/bash

program="./$(grep 'NAME :=' ./Makefile | cut -d'=' -f2 | xargs)"

make
build_status="$?"

if (( build_status != 0 )); then
    exit $build_status;
fi

if ! [ -x "$program" ]; then
    echo "missing $program executable, check if right NAME on Makefile"
    exit 1;
fi

run_test_command() {
    actual=$("${command[@]}" 2>&1)
    status="$?"
    if [[ "$actual" != "$expected" ]]; then
        echo "[BAD] test: ${command[*]}";
        echo "actual:"
        echo "$actual";
        echo ""
        echo "expected:"
        echo "$expected"
        echo ""
        #exit 42;
    elif (( status != expected_status )); then
        echo "[BAD] test: ${command[*]}";
        echo "actual status: $status"
        echo "expected status: $expected_status"
        #exit $status
    else
        echo "[GOOD] test: ${command[*]}";
    fi
}


command=("$program")
expected="Usage: ./PmergeMe (list of natural numbers to be sorted)
ex: ./PmergeMe 10 0 12 22 55 13"
expected_status='11'
run_test_command

command=("$program" "-10")
expected="Error"
expected_status='22'
run_test_command

command=("$program" "10" "20")
expected="10 20"
expected_status='0'
run_test_command

command=("$program" "10" "20" "30")
expected="10 20 30"
expected_status='0'
run_test_command

command=("$program" "10" "20" "30" "40")
expected="10 20 30 40"
expected_status='0'
run_test_command

command=("$program" "10" "20" "30" "40" "50")
expected="10 20 30 40 50"
expected_status='0'
run_test_command


command=("$program" "20" "10")
expected="10 20"
expected_status='0'
run_test_command

command=("$program" "30" "10" "20")
expected="10 20 30"
expected_status='0'
run_test_command

command=("$program" "20" "10" "40" "30")
expected="10 20 30 40"
expected_status='0'
run_test_command

command=("$program" "40" "50" "20" "30" "10"  )
expected="10 20 30 40 50"
expected_status='0'
run_test_command

command=("$program" "10" "40" "30" "60" "20" "90" "70" "80" "50" )
expected="10 20 30 40 50"
expected_status='0'
run_test_command
