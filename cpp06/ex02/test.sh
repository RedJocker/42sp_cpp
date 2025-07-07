#!/bin/bash

program="./inspect"

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
    if [[ "$actual" =~ $expected ]] \
       && [[ ${BASH_REMATCH[1]} == ${BASH_REMATCH[2]} ]] \
       && [[ ${BASH_REMATCH[3]} == ${BASH_REMATCH[4]} ]] \
       && [[ ${BASH_REMATCH[5]} == ${BASH_REMATCH[6]} ]] \
       && [[ ${BASH_REMATCH[7]} == ${BASH_REMATCH[8]} ]] ; then
	echo "[GOOD] test: $command ";
    else
	echo "[BAD] test: $command ";
	if ! [[ "$actual" =~ $expected ]]; then
	    echo 'pattern does not match'
	elif ! [[ ${BASH_REMATCH[1]} == ${BASH_REMATCH[2]} ]]; then
	    echo 'expected first capture group to be equal to second capture group'
	elif ! [[ ${BASH_REMATCH[3]} == ${BASH_REMATCH[4]} ]]; then
	    echo 'expected third capture group to be equal to fourth capture group'
	elif ! [[ ${BASH_REMATCH[5]} == ${BASH_REMATCH[6]} ]]; then
	    echo 'expected fifth capture group to be equal to sixth capture group'
	elif ! [[ ${BASH_REMATCH[7]} == ${BASH_REMATCH[8]} ]]; then
	    echo 'expected seventh capture group to be equal to eighth capture group'
	fi
	echo "actual:"
	echo "$actual";
	echo ""
	echo "expected(regex):"
	echo "$expected"
	exit 1;
    fi
}

command="$program"
expected='^identified ([A-C])\*
identified ([A-C])&

identified ([A-C])\*
identified ([A-C])&

identified ([A-C])\*
identified ([A-C])&

identified ([A-C])\*
identified ([A-C])&$'
run_test_command
