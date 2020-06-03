!/bin/bash

dpkg -l | grep "nmap"
if [ $? != 0  ];then
    sudo apt install nmap
fi
nmap -sn 192.168.1.0/24

