#!/bin/bash
file=$1
sed -i '/^#/d' $file
sed -i '/^\/\//d' $file
sed -i '/^\s*$/d' $file