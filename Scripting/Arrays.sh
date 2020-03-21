#!/bin/bash
# !
#1 @ prints all array elements
arr=('upendra' 'sunil' 'kadre')
echo "Arr : ${arr[@]}"
#2 adding and deleting
echo "adding sushil to arr"
arr[3]='sushil'
echo "Arr : ${arr[@]}"

echo "removing sushil from arr"
unset arr[3]
echo "Arr : ${arr[@]}"

#3 
echo "Arr indices : ${!arr[@]}"
#4
echo "Arr size = ${#arr[@]}"
#5 
echo "adding element at random index leaving some uninitiated"
arr[6]='joshi'
echo "Arr : ${arr[@]}"
echo "Arr indices : ${!arr[@]}"
echo "Arr size = ${#arr[@]}"
