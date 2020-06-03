#!/bin/bash

path=$1
sed -i '/ ^ $ / d' $path
sed -i 's/ \{1,\}/ /g' $path

nl $path > temp
cat temp > $path
rm temp