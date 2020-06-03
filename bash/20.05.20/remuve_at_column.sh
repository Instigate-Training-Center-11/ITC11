#!/bin/bash
file=$1
touch temp
awk '{if ( $2 != "Data" ) { print $0; } }' $file  > temp
cat temp > $file
rm temp
