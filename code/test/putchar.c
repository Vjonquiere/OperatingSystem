#include "syscall.h"
void print(char c, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        PutChar(c + i);
    }  
    PutChar('\n');
}
int
main()
{
    print('a',4);
    Halt();
}
/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -x test/putchar
*/