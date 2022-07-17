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

isPrime()
{
	flag3=1
	n=$1
	if [ $n -eq 1 ]
	then
		return 0
	fi
	for((i=2; i<=n/2; i++))
	do
		if [ $((n%i)) -eq 0 ]
		then
			flag3=0
			break
		fi
	done
	return $flag3
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

primes=()
composites=()

for var in ${arr2[*]}
do
	isPrime $var
	res=$?
	if [ $((res)) -eq 0 ]
	then
		composites+=("${var}")
	else
		primes+=("${var}")
	fi
done

echo "Given Numbers: [${arr2[*]}]"

arr2=(${primes[*]})
echo "Prime Numbers Before Sort: [${primes[*]}]"
qsort 0 $((${#arr2[*]} - 1))
echo "Prime Numbers After Sort: [${arr2[*]}]"

arr2=(${composites[*]})
echo "Composite Numbers Before Sort: [${composites[*]}]"
qsort 0 $((${#arr2[*]} - 1))
echo "Composite Numbers After Sort: [${arr2[*]}]"


