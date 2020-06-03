#!/bin/bash
file=$1
let temp=0
while IFS= read -r line; do
if [ "$temp" -eq 2 ]
then
  tput setaf 2
  echo "$line"
  let temp=0
else
  tput setaf 7	
  echo "$line"
  let temp=temp+1
fi
done < $file


