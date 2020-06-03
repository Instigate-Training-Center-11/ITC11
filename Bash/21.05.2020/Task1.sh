#!/bin/bash
str=$1

sed '/^$/d' -i $str
sed "s/ \{2,50\}//g" -i $str
nl -s :" " $str
