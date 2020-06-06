#!/bin/bash
str=$1

cut -d" " -f2 $str > tmp
count=1
while read LINE
do
	if [[ $LINE = "Data" ]]
	then
		sed -i ''$count'd' $str
	fi
	count=$(($count + 1))
done < tmp
rm tmp
