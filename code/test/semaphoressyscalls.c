#ifdef CHANGED
#include "syscall.h"
#include "vsprintf.h"

int main(){
    sem_t semaphore = SemaphoreCreate(1);
    P(semaphore);
    V(semaphore);
    V(semaphore);
    P(semaphore);
    P(semaphore);
    SemaphoreDelete(semaphore);
    return 0;
}

/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -d s -x test/semaphoressyscalls

The only purpose of this test is to see the basics of UserSemaphores 
(that's why -d s is in the launch command). It test all implemented 
premitives (create, p, v, delete).
This program should not be locked because P->V->V->P->P is not a blocking sequence
for a semaphore initialized to 1.


*/


#endif