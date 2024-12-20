#ifdef CHANGED
#include "syscall.h"

sem_t mutex;

void funcThread(void* a){
    int i;
    
    for (i=0; i<40; i++){
        
        P(mutex);
        PutString("Thread ");
        PutChar((int)a);
        PutChar((int)':');
        PutInt((int)i);
        PutChar((int)'\n');
        V(mutex);
    }
}  


int main(){
    mutex = SemaphoreCreate(1);
    ThreadCreate(funcThread,(void*)'B');
    ThreadCreate(funcThread,(void*)'A');
    ThreadCreate(funcThread,(void*)'C');
    ThreadExit();
    return 1;
}

/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -rs 1234 -x test/threadloop

This program tests the stack allocation of our threads. It creates three threads that just 
count to 40 (it iterates on a local variable) in order to see if stack pointers are correctly
allocated. You can see that each is going to have it own counter, and even tough there are 
contexts switches, the enumeration returns to the good values when each thread is set to current.
You can add -d s argument to see mutexes and threads operation or -d t to see context switches.


*/
#endif