#! /usr/bin/env bash

source=${1%%.*}
make source=$source

if (( $? != 0 )); then
    exit 1
fi

echo
echo -n '$ '

if [ -f i${source}.txt ]; then
    echo "./x${source}.exe < i${source}.txt"
    ./x${source}.exe < i${source}.txt
else
    echo ./x${source}.exe
    ./x${source}.exe
fi
