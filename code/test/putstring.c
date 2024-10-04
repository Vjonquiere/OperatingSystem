#include "syscall.h"

void testPutString()
{
PutString("a\n");
PutString("abcd\n");
PutString("123456\n");
PutString("");
PutString("String longer than the buffer.\n");
PutString("123456789\n");
PutString("Notre appel système ne sait pas bien gérer les accents!\n");
PutString("12345678\n");

}
int
main()
{
testPutString();
Halt();
}

/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -x test/putstring

To test our new syscall PutString, we implemented a function called testPutString.
We have tested different cases that could be problematic if we made mistakes in our code.
We called the function with Strings that are smaller than the size of our buffer to be sure that it would work in the best case.
Since we chose a small buffer (size 8), it a=is really easy to test it for longer strings. We caled our function 
with parameters longer than the buffer to see if it was still working.
Also, we tried it with a string of the size of the buffer, which could be problematic since we need to have 
one char of the buffer as '\0'.
Everything that we have tested in terms of length worked, the only problem is the special characters,
like the accents if we want to print sytrings in french.
*/