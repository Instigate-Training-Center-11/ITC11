#!/bin/bash
str=$1
sed -i '/^#/d;/^\//d;/^$/d' $str
