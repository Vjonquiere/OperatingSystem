#ifdef CHANGED
#include "syscall.h"

void funcThread(void* a){
    PutChar((int)a);
}


void funcThread2(void* a){
    PutChar(GetChar());
}

int main(){
    ThreadCreate((void*)&funcThread2,(void*)'Z');
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
./userprog/nachos -x test/threadlock

The test creates multiple threads that attempt to access `PutChar` and `GetChar` simultaneously.
The purpose is to ensure that concurrent calls to `PutChar` and `GetChar` are properly synchronized,
so that output characters from different threads do not interleave unexpectedly, preserving 
output consistency. For example, 'A' and 'B' are printed by separate threads while 'E' and 'F' 
are printed by the main thread, allowing us to observe if characters appear in the intended sequence.
To finish the test you need to make an input to send the `PutChar` call and see the character written
in the console. 


*/


#endif