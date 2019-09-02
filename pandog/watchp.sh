#!/bin/bash -v
cd /home/pi/work/pandog
if [ ! -f "pecent.txt" ];then
touch pecent.txt
else
rm -f pecent.txt
fi
all=`df -h`
echo $all
echo $all | sed 's/.*T \([0-9]*\)% .*/\1/g' | tee pecent.txt