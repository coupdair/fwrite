#!/bin/bash

fwrite=fwrite.MacOSX
fwrite=fwrite.linux32
#fwrite=fwriteS.exe

start=1
end=10
size=64
start=$1
end=$2
size=$3

digit=4

totalSize=`echo $size*$end-$size*$start+$size*1 | bc`
echo Writing $totalSize MByte '(i.e. >'`echo $totalSize/1024 | bc`' GByte)'

for((i=start;i<end+1;i++))
do
  echo $size | ./$fwrite
  mv fichier.txt file_`printf %0$digit'd' $i`
done
