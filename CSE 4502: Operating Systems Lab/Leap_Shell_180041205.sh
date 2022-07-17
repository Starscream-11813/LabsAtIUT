#!/bin/bash

arr=("$@")
arr2=()
qsort()
{
	l=$1
    	h=$2
    	if [ $l -ge $h ]
    	then
    	    return
    	fi
    	pivot=$(((arr2[l]+arr2[h])/2))
    	i=$l
    	j=$h
    	while [ $i -lt $j ] ; do
    	    if [ ${arr2[$i]} -le $pivot ]
    	    then
    	        i=$((i + 1))
    	    elif [ ${arr2[$j]} -gt $pivot ]
    	    then
    	        j=$((j - 1))
    	    elif [ $i -lt $j ]
    	    then
    	         temp=${arr2[$i]}
   	         arr2[$i]=${arr2[$j]}
   	         arr2[$j]=$temp
   	     fi
   	 done
   	 qsort $l $((i-1))
   	 qsort $i $h
}

isLeap()
{
	flag3=1
	n=$1
	if [ $((n%4)) -eq 0 -a $((n%100)) -ne 0 -o $((n%400)) -eq 0 ]
	then
		return 1
	else
		return 0
	fi
}

if [ ${#arr[@]} -ne 0 ]
then
for var in ${arr[*]}
do
	if [[ $var =~ ^[+-]?[0-9]+$ ]]
	then
		arr2+=("${var}")
	else
		echo "Error: Please give numbers only!"
		arr2=()
		flag=0
		while [ $flag -eq 0 ]
		do
			echo "Enter your numbers again: "
			arr=()
			arr2=()
			read -a arr2
			for var2 in ${arr2[*]}
			do
				if [[ $var2 =~ ^[+-]?[0-9]+$ ]]
				then
					flag=1
				else
					flag=0
					break
				fi
			done
		done
		break
	fi
done
else
	echo "Error: No inputs given!"
	arr=()
	arr2=()
	flag=0
	while [ $flag -eq 0 ]
	do
		echo "Enter your numbers again: "
		arr2=()
		arr=()
		read -a arr2
		for var2 in ${arr2[*]}
		do
			if [[ $var2 =~ ^[+-]?[0-9]+$ ]]
			then
				flag=1
			else
				flag=0
				break
			fi
		done
	done
fi

leaps=()
nonleaps=()

for var in ${arr2[*]}
do
	isLeap $var
	res=$?
	if [ $((res)) -eq 0 ]
	then
		nonleaps+=("${var}")
	else
		leaps+=("${var}")
	fi
done

echo "Given Years: [${arr2[*]}]"

arr2=(${leaps[*]})
echo "Leap Years Before Sort: [${leaps[*]}]"
qsort 0 $((${#arr2[*]} - 1))
echo "Leap Years After Sort: [${arr2[*]}]"

arr2=(${nonleaps[*]})
echo "Non-Leap Years Before Sort: [${nonleaps[*]}]"
qsort 0 $((${#arr2[*]} - 1))
echo "Non-Leap Years After Sort: [${arr2[*]}]"


