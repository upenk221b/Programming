#!/bin/bash
# While loop
num=1
while [ $num -lt 100 ]
do
	echo $num
	num=$((num+2))
done