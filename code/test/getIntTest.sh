#!/bin/bash
for numberToTest in "1234" "1472712" "1264H52" "-123913" "" "12345678901" "-12345678901" "2147483647" "-2147483648"
do
    echo -e "\033[0;34mTesting getInt with Int: '$numberToTest'"
    echo $numberToTest | ./userprog/nachos -d s -x test/getint
done