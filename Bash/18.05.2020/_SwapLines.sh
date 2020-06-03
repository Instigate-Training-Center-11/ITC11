#!/bin/bash
str1=$1
str2=$2

NO_FILE=101

if [[ ! -f "$str*" ]]
then
    echo "File is not exist...error[$NO_FILE]"
    exit $NO_FILE
fi


test1=`sed -n '$=' $str1`
test2=`sed -n '$=' $str2`

if [ $test1 -gt $test2 ]
	then
	res=$test2
	cat $str2 > ~/temp
	for(( i=$(($test2 + 1)); i<=$test1; i++ ))
		do
		sed ''$i'!D' $str1 >> ~/temp
	done

	head -n$((res)) $str1 > $str2
	cat ~/temp > $str1
else
	res=$test1
fi

rm ~/temp
