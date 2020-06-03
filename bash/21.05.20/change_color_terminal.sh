#!/bin/bash

defaultprofile=$(gsettings get org.gnome.Terminal.ProfilesList default)
profileID=$(echo "$defaultprofile" | cut -d "'" -f 2)
gsettings set org.gnome.Terminal.Legacy.Profile:/org/gnome/terminal/legacy/profiles:/:$profileID/ background-color Gray
