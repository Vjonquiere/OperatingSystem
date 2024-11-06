#ifdef CHANGED
#include "syscall.h"

void funcThread(void* a){
    PutChar((int)a);
    //ThreadExit();
}


void funcThread2(void* a){
    PutChar(GetChar());
    //ThreadExit();
}

int main(){
    ThreadCreate((void*)&funcThread2,(void*)'Z', ThreadExit);
    ThreadCreate((void*)&funcThread,(void*)'Z', ThreadExit);
    ThreadCreate((void*)&funcThread,(void*)'Z', ThreadExit);
    ThreadCreate((void*)&funcThread,(void*)'Z', ThreadExit);
    ThreadCreate((void*)&funcThread,(void*)'Z', ThreadExit);
    PutChar('A');
    PutChar('I');
    ThreadExit();
    while(1){}
}


#endif