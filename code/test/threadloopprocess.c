#ifdef CHANGED
#include "syscall.h"
#include "vsprintf.h"

void funcThread(void* a){
    PutChar((int)a);
}  

int main(){
    ThreadCreate(funcThread,(void*)'B');
    ThreadCreate(funcThread,(void*)'A');
    ThreadCreate(funcThread,(void*)'C');
    ThreadCreate(funcThread,(void*)'D');
    ThreadCreate(funcThread,(void*)'E');
    ThreadCreate(funcThread,(void*)'F');
    ThreadCreate(funcThread,(void*)'G');
    ThreadCreate(funcThread,(void*)'H');
    ThreadExit();
    return 1;
}

/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -rs 1234 -x test/threadloopprocess

This program only launch several threads. It is not very usefull alone because it does the same
things as threadloop. It is used by multipleprocesses in order to test processes and thread
on large almount.

*/
#endif