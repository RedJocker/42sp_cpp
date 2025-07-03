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
 
