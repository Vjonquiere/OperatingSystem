#ifdef CHANGED
#include "syscall.h"

void funcThread2(void* a){
    char n[5];
   GetString(n, 5);
}

int
main()
{
    ForkExec("test/testrelease");
    ThreadCreate((void*)&funcThread2,(void*)'Z');
    ThreadExit();
    return 1;
}


/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -rs 1234 -x test/forcereleasetest

This test shows that the force release of the lock for getstring works and that the thread
removed releases the lock before being killed.
Calls the test testrelease that uses PutString and GetString. 
Since both processes call Get§String, one of them is going to have the lock and the second one will sleep.
PutString will be done faster than GetSrtiong since it is only called in the second process and will Exit 
(all the other threads of the process will be killed). Depending on the scheduling, either the second process 
has the Getstring lock and needs to be released, or the first one has it and the second process needs to be 
removed from the queue of threads waiting for the lock.

To see all threads, mutexes, processes debugs labels add `-d s` to the launch command 

*/
#endif