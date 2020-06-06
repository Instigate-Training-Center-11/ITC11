#!/bin/bash

function childs {
	procname=$1
	pgrep $procname > tmp

	while read PID
	do
	echo "$PID    ------ childs:------" >> pstree.txt
	ps --forest -o pid=, -g $(ps -o sid= -p $PID) >> pstree.txt
	done < tmp
}

childs $1