#!/bin/bash
for charToTest in 'a' 'z' '\n' ''
do
    echo -e "\033[0;34mTesting getChar with char: '$charToTest'"
    printf $charToTest | ./userprog/nachos -d s -x test/getchar
done