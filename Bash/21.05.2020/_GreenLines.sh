#!/bin/bash
str=$1

NO_FILE=101

if [[ ! -f "$str" ]]
then
    echo "File is not exist...error[$NO_FILE]"
	exit $NO_FILE
fi

count=0
while read LINE
do
count=$(($count + 1))
if [ $(($count % 3)) = 0 ]
then
	echo -e "\e[32m$LINE\e[0m"
else
	echo $LINE
fi
done < $str
