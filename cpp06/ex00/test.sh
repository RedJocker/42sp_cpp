#!/bin/bash

make
build_status="$?"

if (( build_status != 0 )); then
    exit $build_status;
fi

if ! [ -x ./convert ]; then
    echo 'missing ./convert executable, check if right NAME on Makefile'
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

command="./convert"
expected='Usage: converter strToConvert'
run_test_command
#
command="./convert 1"
expected=$(cat <<EOF
char: Non displayable
int: 1
float: 1.0f
double: 1.0
EOF
)
run_test_command
#
command="./convert 1f"
expected=$(cat <<EOF
char: Non displayable
int: 1
float: 1.0f
double: 1.0
EOF
)
run_test_command
#
command="./convert 1.0"
expected=$(cat <<EOF
char: Non displayable
int: 1
float: 1.0f
double: 1.0
EOF
)
run_test_command
#
command="./convert 1.0f"
expected=$(cat <<EOF
char: Non displayable
int: 1
float: 1.0f
double: 1.0
EOF
)
run_test_command
#
command="./convert 1.00f"
expected=$(cat <<EOF
char: Non displayable
int: 1
float: 1.0f
double: 1.0
EOF
)
run_test_command
#
command="./convert 1.000000000000001"
expected=$(cat <<EOF
char: Non displayable
int: 1
float: 1.0f
double: 1.000000000000001
EOF
)
run_test_command
#
command="./convert 1.000000000000001f"
expected=$(cat <<EOF
char: Non displayable
int: 1
float: 1.0f
double: 1.000000000000001
EOF
)
run_test_command
#
command="./convert a"
expected=$(cat <<EOF
char: 'a'
int: 97
float: 97.0f
double: 97.0
EOF
)
run_test_command
#
command="./convert 97"
expected=$(cat <<EOF
char: 'a'
int: 97
float: 97.0f
double: 97.0
EOF
)
run_test_command
#
command="./convert 97f"
expected=$(cat <<EOF
char: 'a'
int: 97
float: 97.0f
double: 97.0
EOF
)
run_test_command
#
command="./convert 97.0"
expected=$(cat <<EOF
char: 'a'
int: 97
float: 97.0f
double: 97.0
EOF
)
run_test_command
#
command="./convert 97.0f"
expected=$(cat <<EOF
char: 'a'
int: 97
float: 97.0f
double: 97.0
EOF
)
run_test_command
command="./convert Z"
expected=$(cat <<EOF
char: 'Z'
int: 90
float: 90.0f
double: 90.0
EOF
)
run_test_command
#
command="./convert }"
expected=$(cat <<EOF
char: '}'
int: 125
float: 125.0f
double: 125.0
EOF
)
run_test_command
#
command="./convert 1.23456789123456789"
expected=$(cat <<EOF
char: Non displayable
int: 1
float: 1.234568f
double: 1.234567891234568
EOF
)
run_test_command
#
command="./convert 9876543210"
expected=$(cat <<EOF
char: Impossible
int: Impossible
float: 9.876543e+09.0f
double: 9876543210.0
EOF
)
run_test_command
