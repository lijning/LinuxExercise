#! /bin/bash
# name: countfiles
# usage: countfiles [dir path]
# author: Jianing Li 3150101123
# Read n numbers, calculate the sum, max and min of them, and arrange them in an ascendant order.
#
echo "input integers"
read -a nums
declare sumv=0 max=-99999 min=99999
for num in ${nums[*]}
do
	((sumv=$sumv+$num))
	
	if (($num>$max))
	then
		max=$num
	fi
	if (($num<$min))
	then
		min=$num
	fi
done
echo "sum:" $sumv "min:" $min "max:" $max
#echo ${nums[@]} #sort $nums
declare -i high=$max low=$min
echo 'after sorting:'
echo $min
for ((i=1;i<${#nums[*]};i++))
do
	for va in ${nums[*]}
	do
		(($va>$low))&&(($va<$high))&&high=$va
	done
	echo $high
	low=$high
	high=$max
done
