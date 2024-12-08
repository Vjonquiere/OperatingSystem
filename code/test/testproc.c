#ifdef CHANGED

#include "syscall.h"

int main()
{
    ForkExec("test/userpages0");
    ForkExec("test/userpages1");
    return 0;
}


/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -rs 1234 -x test/testproc

This test creates two new processes that are executing the tests program userpages0 and userpages1.
Theses processes have almost the same code, the only difference is the change of strings being printed (the THIS and THAT).
Shows that several processes can be created and executed.
Shows that we can have threads in processes, and that ThreadExit works.


To see all threads, mutexes, processes debugs labels add `-d s` to the launch command 

*/

#endif