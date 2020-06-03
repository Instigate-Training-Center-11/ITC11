#!/bin/bash

function proc {

    read -p "input the process name >> " process_name

    ppid_array=$(ps axf | grep "$process_name" | grep -v grep | awk '{print $1}')
    res=$(echo $ppid_array | awk '{print $1}')

    echo "$(ps --forest -o pid=, -g $(ps -o sid= -p "$res"))"
}

proc > file
