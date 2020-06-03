#!/bin/bash

ps -A | awk '{print $1}' | sed "1d" > tmp

readarray PID < tmp
size=${#PID[@]}
for (( i=$size - 1; i >= 0; i-- ))
do
	count=`pstree -p ${PID[i]} | wc -l`
	if [ $count -eq 2 ]
	then
		pkill -P -9 $PID && kill $PID
	fi
done
rm tmp
