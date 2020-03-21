#! /bin/bash
#arr=($(cat))
arr[0]="baba"
arr[1]="babs"
arr[2]="bab"

n=${#arr[@]}
regex="baba"

for (( i=0;i<$n;i++ ))
do
    if  [[ "${arr[$i]}"=="$regex" ]]
    then
      echo "${arr[$i]}"
    fi
done

