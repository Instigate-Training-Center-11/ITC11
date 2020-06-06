#!/bin/bash
read -p "Insert dir for search(by default HOME): " dir
read -p "Insert file name: " name

if [[ $dir = " " ]]
then
    dir=$HOME
fi
ls -l $dir | awk '{print $9}' | grep "^$name*" | sed "1d" > tmp
head -n3 tmp
tail -n3 tmp
rm tmp