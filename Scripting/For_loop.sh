#!/bin/bash
#1 list the values one by one
echo "Bash vesion : $BASH_VERSION"
echo  "Print  1 2 3"
for i in 1 2 3
do 
	echo $i
done

#2 give values in truncated format {1..N} (works on bash 3.0+)
echo  "Print  1-10"
for j in {1..10}
do
	echo $j
done

#3 give values in truncated format + give incrementation value (bash 4.0+)
echo "even values till 10"
for k in {0..10..2} 
do
	echo $k
done

#4 general C type syntax
echo "odd values till 10 using C type Syntax"
for (( m=1; m<10; m=$(( m+2 )) ))
do
	echo $m
done
