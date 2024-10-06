#!/bin/bash
for stringToTest in "azer" "ae\n" "" "azertyu" "1234567" "12345678" "12345678910"
do
    echo -e "\033[0;34mTesting getString with string: '$stringToTest'"
    printf $stringToTest | ./userprog/nachos -d s -x test/getstring
done

for stringToTest in "è à € £" "long string" "s p a c e"
do
    echo -e "\033[0;34mTesting getString with string: '$stringToTest'"
    echo $stringToTest | ./userprog/nachos -d s -x test/getstring
done