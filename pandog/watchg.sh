#!/bin/bash -v
cd /home/pi/work/pandog
if [ ! -f "g.txt" ];then
touch g.txt
else
rm -f g.txt
fi
all=`df -h`
echo $all
echo $all | sed 's/.*T \([0-9]*\)G .*/\1/g' | tee g.txt