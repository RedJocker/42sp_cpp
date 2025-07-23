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
    # Run the command stored in the array
    actual=$("${command[@]}")
    status="$?"
    if [[ "$actual" != "$expected" ]]; then
        echo "[BAD] test: ${command[*]}";
        echo "actual:"
        echo "$actual";
        echo ""
        echo "expected:"
        echo "$expected"
        echo ""
        exit 42;
    elif (( status != expected_status )); then
        echo "[BAD] test: ${command[*]}";
        echo "actual status: $status"
        echo "expected status: $expected_status"
        exit $status
    else
        echo "[GOOD] test: ${command[*]}";
    fi
}

# Define commands as arrays to prevent shell expansion
command=("$program")
expected="Usage: ./RPN (list of operands and operators using polish postfix notation)
ex: ./RPN  8 9 * 9 - 9 - 9 - 4 - 1 +"
expected_status='11'
run_test_command

command=("$program" "1")
expected="1"
expected_status='0'
run_test_command

command=("$program" "(1)")
expected="Error"
expected_status='22'
run_test_command

command=("$program" "1" "2")
expected="Error"
expected_status='22'
run_test_command

command=("$program" "1" "2" "+")
expected="3"
expected_status='0'
run_test_command

command=("$program" "1" "2" "-")
expected="-1"
expected_status='0'
run_test_command

command=("$program" "1" "2" "*")
expected="2"
expected_status='0'
run_test_command

command=("$program" "1" "2" "/")
expected="0"
expected_status='0'
run_test_command

command=("$program" "4" "2" "+")
expected="6"
expected_status='0'
run_test_command

command=("$program" "4" "2" "-")
expected="2"
expected_status='0'
run_test_command

command=("$program" "4" "2" "*")
expected="8"
expected_status='0'
run_test_command

command=("$program" "4" "2" "/")
expected="2"
expected_status='0'
run_test_command

command=("$program" "8" "9" "*" "9" "-" "9" "-" "9" "-" "4" "-" "1" "+")
expected="42"
expected_status='0'
run_test_command

command=("$program" "7" "7" "*" "7" "-")
expected="42"
expected_status='0'
run_test_command

command=("$program" "1" "2" "*" "2" "/" "2" "*" "2" "4" "-" "+")
expected="0"
expected_status='0'
run_test_command

command=("$program" "(1" "+" "1)")
expected="Error"
expected_status='22'
run_test_command
