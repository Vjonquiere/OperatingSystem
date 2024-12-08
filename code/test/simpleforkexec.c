#ifdef CHANGED

#include "syscall.h"
int main()
{
ForkExec("test/putchar");
ForkExec("test/putchar");
//while(1);
return 0;
}


/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -rs 1234 -x test/simpleforkexec

This test creates two new processes that are executing the test program of PutChar.
Shows that several processes can be created and executed.
For the test of action II.1, we had the while(1) since we weren't implementing the exit of 
processes yet. For the next actions, we commented it.

To see all threads, mutexes, processes debugs labels add `-d s` to the launch command 

*/


#endif