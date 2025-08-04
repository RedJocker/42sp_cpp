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

## BEGIN CASES

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

command=("$program" 90 13 0 2 26 54 57 47 81 78 58 76 15 30 11 0 23)
expected="0 0 2 11 13 15 23 26 30 47 54 57 58 76 78 81 90"
expected_status='0'
run_test_command

command=("$program" 53 22 94 29 44 29 42 78 18 55 60 71 29 1 10 26 10 4 43)
expected="1 4 10 10 18 22 26 29 29 29 42 43 44 53 55 60 71 78 94"
expected_status='0'
run_test_command

command=("$program" 37 13 38 97 5 67 48 77 7 15 8 36 99 29 59 31 91 40 78 44)
expected="5 7 8 13 15 29 31 36 37 38 40 44 48 59 67 77 78 91 97 99"
expected_status='0'
run_test_command

command=("$program" 36 43 35 62 30 72 85 97 89 82 91 82 95 73 67 53 8 22 93 70 39)
expected="8 22 30 35 36 39 43 53 62 67 70 72 73 82 82 85 89 91 93 95 97"
expected_status='0'
run_test_command

command=("$program" 87 81 70 84 86 85 55 52 9 16 72 26 79 30 64 90 69 25 47 66 8 46)
expected="8 9 16 25 26 30 46 47 52 55 64 66 69 70 72 79 81 84 85 86 87 90"
expected_status='0'
run_test_command

command=("$program" 40 43 13 15 87 20 28 32 94 2 84 19 60 56 95 14 80 83 93 35 32 24)
expected="2 13 14 15 19 20 24 28 32 32 35 40 43 56 60 80 83 84 87 93 94 95"
expected_status='0'
run_test_command

command=("$program" 19 12 65 26 96 80 49 49 85 60 89 12 73 81 92 29 26 41 99 53 23 53 91)
expected="12 12 19 23 26 26 29 41 49 49 53 53 60 65 73 80 81 85 89 91 92 96 99"
expected_status='0'
run_test_command

command=("$program" 71 20 38 18 41 39 87 14 42 46 31 80 62 64 27 3 85 61 28 92 31 60 78)
expected="3 14 18 20 27 28 31 31 38 39 41 42 46 60 61 62 64 71 78 80 85 87 92"
expected_status='0'
run_test_command

command=("$program" 74 79 88 35 40 24 2 43 49 11 20 93 42 50 59 20 6 24 10 44 48 9 5)
expected="2 5 6 9 10 11 20 20 24 24 35 40 42 43 44 48 49 50 59 74 79 88 93"
expected_status='0'
run_test_command

command=("$program" 95 92 61 52 72 45 58 95 20 27 56 12 89 1 45 4 42 48 77 46 41 30 57)
expected="1 4 12 20 27 30 41 42 45 45 46 48 52 56 57 58 61 72 77 89 92 95 95"
expected_status='0'
run_test_command




for size in {3000..3001}; do # testSize
    for run in {1..1000}; do  # how many tests with that size
	numbers=();
	for ((i=0; i < size; i++)); do
            numbers+=($((RANDOM % 100)) )
	done
        expected=$(printf "%s\n" "${numbers[@]}" | sort -n | xargs)
        
        command=("$program" "${numbers[@]}")
        expected_status='0'
        run_test_command
    done
done
