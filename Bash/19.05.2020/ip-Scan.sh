#!/bin/bash

ROOT_UID=0
ER_NOTROOT=202

if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Need root permission."
  exit $ER_NOTROOT
fi

if dpkg -l | grep arp-scan > log.tmp
then
	echo Arp-scan is installed in your PC
	echo Scanning...
else
 
sudo apt install arp-scan &> log.tmp
fi
ip r l | cut -d " " -f1 > log.tmp
ipmask=`grep "192.168*" log.tmp`
sudo arp-scan $ipmask | sed '/^[[:alpha:]]/d' > log.tmp
cat log.tmp
