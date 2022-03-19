#!/bin/bash
#----------------------------------------------------
# ./run.sh -d -f tuple.c
# bash run.sh -d -f tuple.c
#----------------------------------------------------
while getopts ":f:d" option; do
   case $option in
      f) # file
          file=$OPTARG
          ;;
      d) # rm file
          rm_file=1
          ;;
   esac
done

echo "file: $file"

file_arr=($(echo $file | tr '.' "\n"))

name="${file_arr[0]}"

gcc -ansi -Wall "$file" -o $name
echo "---------------------------------------------------"
./$name
echo ""
echo "---------------------------------------------------"

#echo $rm_file
echo ""
if (( rm_file == 1  )); then
    echo "removing cache file: $name"
    rm $name
fi

echo ""

