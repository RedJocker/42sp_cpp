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
expected="10 20 30 40 50 60 70 80 90"
expected_status='0'
run_test_command

command=("$program" "30" "10" "50" "60" "40" "80" "20" "90" "70" )
expected="10 20 30 40 50 60 70 80 90"
expected_status='0'
run_test_command

command=("$program" 88 40 69 95 13 7 61 59)
expected="7 13 40 59 61 69 88 95"
expected_status='0'
run_test_command

command=("$program" 59 89 83 75 56 45 14 59 42)
expected="14 42 45 56 59 59 75 83 89"
expected_status='0'
run_test_command

command=("$program" 18 21 91 0 31 42 76 19 86 79)
expected="0 18 19 21 31 42 76 79 86 91"
expected_status='0'
run_test_command

command=("$program" 86 29 69 64 11 10 81 47 45 14)
expected="10 11 14 29 45 47 64 69 81 86"
expected_status='0'
run_test_command

command=("$program" 74 49 1 65 72 18 67 66)
expected="1 18 49 65 66 67 72 74"
expected_status='0'
run_test_command

command=("$program" 75 51 2 93 63 31 28 18 33)
expected="2 18 28 31 33 51 63 75 93"
expected_status='0'
run_test_command

command=("$program" 52 97 40 41 83 31 19 26 83 33)
expected="19 26 31 33 40 41 52 83 83 97"
expected_status='0'
run_test_command


# for size in {2..10}; do
#     for run in {1..5}; do  # 5 tests per size
# 	numbers=();
# 	for ((i=0; i < size; i++)); do
#             numbers+=($((RANDOM % 100)) )
# 	done
#         expected=$(printf "%s\n" "${numbers[@]}" | sort -n | xargs)
        
#         command=("$program" "${numbers[@]}")
#         expected_status='0'
#         run_test_command
#     done
# done
