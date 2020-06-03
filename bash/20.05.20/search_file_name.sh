#!/bin/bash

read -p "input the folder path >> " path
read -p "input the word >> " word

find $path -name "$word*" | head -n 3
find $path -name "$word*" | tail -n 3
