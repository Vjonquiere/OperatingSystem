#ifdef CHANGED
#include "syscall.h"


void funcThread(void* a){
    PutChar(GetChar());
}

int main(){
    ThreadCreate((void*)&funcThread,(void*)'A');
    ThreadCreate((void*)&funcThread,(void*)'B');
    PutChar('E');
    PutChar('F');
    ThreadExit();
    return 1;
}

/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -rs 1234 -x test/threadgetchar

This test create two threads that tries to read from the standard input. 
Because `GetChar` is now protected, we can call it on two threads simultaneously.
To complete a PutChar you need to enter a char then CTRL+D to times and see your
characers printed.


To see all threads, mutexes debugs labels add `-d s` to the launch command 

*/


#endif