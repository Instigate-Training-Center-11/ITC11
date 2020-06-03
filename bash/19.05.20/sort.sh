sed -i '/^$/d' ./txt
sizeline=$(cat txt | wc -l)
echo "$sizeline"
echo "$txt"

mapfile -t arr < txt

sort () {
    for ((i=0; i <= $((${#arr[@]} - 2)); ++i))
    do
        for ((j=((i + 1)); j <= ((${#arr[@]} - 1)); ++j))
        do
            if [[ ${arr[i]} > ${arr[j]} ]]
            then
                tmp=${arr[i]}
                arr[i]=${arr[j]}
                arr[j]=$tmp
            fi
        done
    done
}

sort ${arr[@]}
echo ${arr[0]} > txt
for ((i=1; i <= $((${#arr[@]} - 1)); ++i))
do
    echo ${arr[i]} >> txt
done