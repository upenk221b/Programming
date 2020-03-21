#!/bin/bash
# 1 arithmatic
n1=4
n2=8
f1=4.123
echo "n1=$n1 and n2=$n2 f1=$f1"
echo "add n1 n2: "
echo "$n1+$n2" | bc
echo "multiply n1 n2 and store in n1 :"
n1=$(("$n1*$n2" | bc))
echo $n1

#2 floating point 
echo "floating point operations on n2 and f1 precision = 0.000"
echo "multiply "
echo "scale=5;$n1*$f1" | bc

#3 math liabrary functions like sqrt etc using -l option
echo "sqrt(24):"
echo "scale=3;sqrt(24)" | bc -l
printf "%.3f" $(echo "sqrt(24)" | bc -l)
#printf round offs it correctly as correct ans is 4.8988....

