#! /usr/bin/env bash

source=${1%%.*}
make source=$source

if (( $? != 0 )); then
    exit 1
fi

echo

if [ -f i${source}.txt ]; then
    echo ./${source}.exe < i${source}.txt
    ./${source}.exe < i${source}.txt
else
    echo ./${source}.exe
    ./${source}.exe
fi
