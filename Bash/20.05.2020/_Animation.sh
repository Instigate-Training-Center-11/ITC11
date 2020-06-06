#!/bin/bash

y=0
x=0
max_x=120
space=""

draw_right() {
    local  line[0]='                    '
    local  line[1]='                    '
    local  line[2]='                    '
    local  line[3]='         #          '
    local  line[4]='         ##         '
    local  line[5]='         ###        '
    local  line[6]='         ####       '
    local  line[7]='##############      '
    local  line[8]='###############     '
    local  line[9]='##############      '
    local line[10]='         ####       '
    local line[11]='         ###        '
    local line[12]='         ##         '
    local line[13]='         #          '
    local line[14]='                    '
    local line[15]='                    '

    space=""
    for ((j = 0; j < $2; j++)) ; do
      space="$space "
    done
    for index in {0..15}; do
        echo "$space${line[$index]}"
    done
}

move() {
    if ((x < max_x))
    then
        ((x++))
    fi

    tput cup $y 0
    draw_right $y $x
}

main() {

    clear

    for ((i=0; i < $max_x; i++))
    do
		move
        sleep .05
    done
}

main