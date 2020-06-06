#!/bin/bash
read -p "Enter a color of background <black|blue|green|cyan|red|magenta|yellow|white>:  " background
read -p "Enter a color of foreground:  " foreground

setterm --term linux --back $background --fore $foreground