#!/bin/bash
cd /home/pi/work/pandog
if [ ! -f "all.txt" ];then
touch all.txt
else
rm -f all.txt
fi
all=`df -h`
#echo $all
var=${all%\%*}
var=${var%T*}
var=${var%T*}
var=${var#*sda2 }
echo $var | tee all.txt