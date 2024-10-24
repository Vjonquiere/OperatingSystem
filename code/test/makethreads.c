#ifdef CHANGED
#include "syscall.h"

void funcThread(void* a){
    PutChar((int)a);
    ThreadExit();
}

int main(){
    ThreadCreate(funcThread,(void*)'Z');

    ThreadExit();
    return 0;
}


#endif