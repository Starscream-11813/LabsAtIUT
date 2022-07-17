#!/bin/bash
# My ID is 180041205. So, Algorithm ID = (180041205%5)+1 = 0 + 1 = 1 (Quick Sort)
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
   	 #echo "Debug"
   	 qsort $l $((i-1))
   	 qsort $i $h
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
			#unset arr2[-1]
			#unset arr2[-1]
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
		#unset arr2[-1]
		#unset arr2[-1]
		break
	fi
done
else
	echo "Error: No inputs given!"
	#echo "Enter your numbers again: "
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

echo "Before Sort: [${arr2[*]}]"
qsort 0 $((${#arr2[*]} - 1))
echo "After Sort: [${arr2[*]}]"


