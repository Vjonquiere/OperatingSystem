#ifdef CHANGED
#include "syscall.h"

void funcThread(void* a){
    PutString("test\n");
    Exit(1);
}


void funcThread2(void* a){
    char n[5];
    GetString(n, 5);
    PutString(n);
}

int main(){
    ThreadCreate((void*)&funcThread2,(void*)'Z');
    ThreadCreate((void*)&funcThread,(void*)'A');
    ThreadExit();
    return 1;
}

/*
Explanation in forcereleasetest
Helping program to show the implicit force release of a lock when a thread is being killed.
*/
#endif