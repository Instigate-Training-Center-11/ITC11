#!/bin/bash

ps -o pid,user,%mem ax | sort -k3 -r > tmp
head -n 6 tmp > tmp.tmp && mv tmp.tmp tmp
cut -d" " -f4 tmp
rm tmp