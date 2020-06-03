#!/bin/bash

read -p "input the word >> " word
read -p "input the destination >> " folder

find . -name "$word*" -print | zip result.zip -@

if [ ! -d "$folder" ]; then
    mkdir $folder
fi
mv ./result.zip $folder
