#!/bin/bash
str=$1
NO_FILE=101

if [[ ! -f "$str" ]]
then
    echo "File is not exist...error[$NO_FILE]"
    exit $NO_FILE
fi

readarray array < $str
size=${#array[@]}
for ((i=0; i <= $(($size - 2)); ++i))
    do
        for (( j=$(($i + 1)); j <= $(($size - 1)); ++j ))
        do
            if [[ ${array[i]} > ${array[j]} ]]
            then
                tmp=${array[i]}
                array[i]=${array[j]}
                array[j]=$tmp
            fi
        done
    done

for i in "${array[@]}"
do
	echo $i >> $str
done

sed -i '1,'$size'd' $str
