#ifdef CHANGED
#include "syscall.h"
int main(){
    ForkExec("test/threadloopprocess");
    ForkExec("test/threadloopprocess");
    ForkExec("test/threadloopprocess");
    ForkExec("test/threadloopprocess");
    ForkExec("test/threadloopprocess");
    return 1;
}
#endif

/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -rs 1234 -x test/multipleprocesses

This test is here to see if we can launch multiple processes that execute a lot of thread each.
⚠️ Do not forget to increase the number of physical pages in machine.h and the stack size 
of your user in addrspace.cc.
Each process is going to launch many threads that will do a simple GetChar before going down.
The program will exit automaticaly after all processes cleanup.


To see all threads, mutexes, processes debugs labels add `-d s` to the launch command 

*/