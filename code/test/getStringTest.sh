#!/bin/bash
for stringToTest in "azer" "ae\n"
do
    echo -e "\033[0;34mTesting getString with string: '$stringToTest'"
    printf $stringToTest | ./userprog/nachos -d s -x test/getstring
done