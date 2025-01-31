#!/bin/bash
read -p "Enter size of array: " size
nums=()
for (( i=0; i<size; i++ )); do
    read -p "Enter number: " num
    nums+=($num)
done

echo "Array: "
for (( i=0; i<size; i++ )); do
    echo -n  "${nums[i]} "
done

declare -A freq
for (( i=0; i<size; i++ )); do
    if [[ ${freq[${nums[i]}]} ]]; then
        freq[${nums[i]}]=$((${freq[${nums[i]}]}+1))
    else
        freq[${nums[i]}]=1
    fi
done

echo -e "\nFrequency of numbers: "
for key in ${!freq[@]}; do
    echo "$key: ${freq[$key]}"
done
