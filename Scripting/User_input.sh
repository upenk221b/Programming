#!/bin/bash
#1
echo -e "Enter your name :\c"
read name
echo "you are $name."

#2 (works same as 1)
read -p "Enter your name" name2
echo "you are $name2"

#3(read silently)
read -sp "Enter your name" name3
echo "you are $name3"

#4 (read with System variable $REPLY)
read -p "Enter your name" 
echo "you are $REPLY"








#5 (read array)
read -a family
echo family: ${family[0]},${family[1]},${family[2]},${family[3]}
