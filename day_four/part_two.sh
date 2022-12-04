#!/bin/bash
readonly file="input_files/puzzle_input.txt"

x_overlaps_y() {
    x_start=`echo "$1" | cut -d- -f1`; x_end=`echo "$1" | cut -d- -f2`
    y_start=`echo "$2" | cut -d- -f1`; y_end=`echo "$2" | cut -d- -f2`
    if [ "$x_start" -gt "$y_end" ] || [ "$y_start" -gt "$x_end" ]; then
        return 0
    fi
    return 1
}

main() {
    let score=0

    while read line; do
        x=`echo "$line" | cut -d, -f1`
        y=`echo "$line" | cut -d, -f2`
        overlaps=`x_overlaps_y "$x" "$y"; echo "$?"`
        (( score += ( overlaps ) ))
    done < <(grep "" "$file")

    echo "Answer = $score"
}

main; exit 0