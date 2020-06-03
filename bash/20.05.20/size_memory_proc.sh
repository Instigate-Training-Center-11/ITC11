#!/bin/bash
output=$(ps -eo pid,%mem,%cpu --sort=-%mem)
echo "$output" | head -n 6

