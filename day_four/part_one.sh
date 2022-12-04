#!/bin/bash
readonly file="input_files/puzzle_input.txt"

x_contains_y() {
    x_start=`echo "$1" | cut -d- -f1`; x_end=`echo "$1" | cut -d- -f2`
    y_start=`echo "$2" | cut -d- -f1`; y_end=`echo "$2" | cut -d- -f2`
    if [ "$y_start" -ge "$x_start" ] && [ "$y_end" -le "$x_end" ]; then
        return 1
    fi
    return 0
}

main() {
    let score=0

    while read line; do
        x=`echo "$line" | cut -d, -f1`
        y=`echo "$line" | cut -d, -f2`
        xy=`x_contains_y "$x" "$y"; echo "$?"`
        yx=`x_contains_y "$y" "$x"; echo "$?"`
        (( score += ( xy | yx ) ))
    done < <(grep "" "$file")

    echo "Answer = $score"
}

main; exit 0