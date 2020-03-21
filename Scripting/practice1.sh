#! /bin/bash
declare -A arr
read -p "A[x][y] Enter x and y :" x
read y
for(( i=0;i<$x;i++ ))
do
	for(( j=0;j<$y;j++ ))
	do
		 arr[$i,$j]=$RANDOM
	done
	echo 
done

for(( i=0;i<$x;i++ ))
do
	for(( j=0;j<$y;j++ ))
	do
		 echo "${arr[$i,$j]}"
	done
	echo 
done
echo "${!arr[@]}"
