#ifdef CHANGED
#include "syscall.h"

void funcThread(void* a){
    PutChar((int)a);
    //ThreadExit();
}

int main(){
    ThreadCreate(funcThread,(void*)'Z');

    ThreadExit();
    return 0;
}

/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -rs 1234 -x test/makethreads

This program only tests the creation and execution of a thread by displaying
the letter `Z` with `PutChar` given threw thread arguments. It ensure that 
modifications during the dev won't break the basics of our thread (creation, deletion).
(for example when we modified the auto-exit of our threads, this program allowed us to
see that something went wrong)

To see all threads, mutexes debugs labels add `-d s` to the launch command 

*/


#endif