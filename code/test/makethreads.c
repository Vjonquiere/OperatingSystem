#ifdef CHANGED
#include "syscall.h"

void funcThread(void* a){
    PutChar((int)a);
    ThreadExit();
}

int main(){
    ThreadCreate((void*)&funcThread,(void*)'Z');

    while(1){}
}


#endif