#!/bin/bash
# #? use echo for Print
# echo "Enter first Number: " #! To print use echo 
# #? use read for Input
# read a #! To Input use read 
# echo "Enter second Number: "
# read b
# res=$((a + b))
# echo "Output: "$res

#! Conditions Statement
# Syntax: 
#     if [ Conditions ]
#         then
#             commands
#     fi

#! Let's compare two numbers and find their relationship:
# echo "Enter first number: "
# read x;
# echo "Enter first number: "
# read y;
# # echo $x; echo $y;
# if [ $x -gt $y ] # -gt -> Greater
# then
# echo x is greater then y
# elif [ $x -lt $y ] # -lt -> lesser
# then 
# echo x is less then y
# elif [ $x -eq $y ] # -eq -> equal
# then 
# echo x is equal to y
# fi
#! Beautiful way to write if else Statement:
# Syntax:
#     if [[ condition ]]
#     then
#         statement
#     elif [[ condition ]]; then
#         statement 
#     else
#         do this by default
#     fi

#! Looping and skipping
#! looping with numbers
# for i in {1..5}
# do
#     echo $i
# done
#! Output:-   1
            # 2
            # 3
            # 4
            # 5
#! looping with string
# for X in shaid brishti ruhi raian
# do
#     echo $X
# done

# while loop
# i=1
# while [[ $i -le 10 ]]; do
#     echo "$i"
#     ((i += 1))
# done

#! ❯ bash a.sh > out.txt; cat out.txt
LINE=1
while read -r CURRENT_LINE
    do 
        echo "$LINE: $CURRENT_LINE"
    ((LINE++))
done < "in.txt"
