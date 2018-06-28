#!/bin/bash
#
declare -a rand
declare -i max=0
declare -i min=1000000

for i in {0..9}; do
    rand[$i]=$RANDOM       # $RANDOM的值是一个随机数
echo ${rand[$i]}
    [ ${rand[$i]} -gt $max ] && max=${rand[$i]}
    [ ${rand[$i]} -lt $min ] && min=${rand[$i]}
done 

echo "The  MAX number is $max"
echo "The  MIN number is $min"
