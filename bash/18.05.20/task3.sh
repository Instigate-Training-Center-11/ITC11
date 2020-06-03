#!/bin/bash

if [ ! -d "1_math" ]; then
    mkdir "1_math"
fi

if [ ! -d "1_economy" ]; then
    mkdir "1_economy"
fi

find . -name 'math*' -exec mv -t './1_math/' {} +
find . -name 'economy*' -exec mv -t './1_economy/' {} +