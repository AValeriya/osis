#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 filename"
    exit 1
fi

prev_char="."
while IFS= read -r line; do
    for (( i=0; i<${#line}; i++ )); do
        char="${line:i:1}"
        if [[ $prev_char == "." || $prev_char == "?" || $prev_char == "!"  || $prev_char == $'\t' ]]; then
            line="${line:0:i}${char^^}${line:i+1}"
        fi
        prev_char="$char"
    done
    echo "$line"
done < "$1"

