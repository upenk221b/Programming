#!/bin/bash
# If - else statements
read -p "Enter num: " num
#1 if then
if [ $num -gt 10 ]
then
	echo "#1 $num is greater than 10"
fi
#2 if then else
if [ $num -gt 10 ]
then
	echo "#2 $num is greater than 10"
else
	echo "#2 $num is not greater than 10"
fi

#3 if - else ladder
read -p "Enter your marks " marks
if (( "$marks" < 40 ))
then
	echo "#3 You are failed!"
elif (( "$marks" >= 40 )) && (( "$marks" <= 60 ))
then 
	echo "#3 Your grade is C"
elif (( "$marks" >= 60 )) && (( "$marks" <= 80 ))
then 
	echo "#3 Your grade is B"
elif (( $marks >= 80 ))
then 
	echo "#3 Your grade is A"
fi