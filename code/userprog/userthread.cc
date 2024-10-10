#ifdef CHANGED
#include "system.h"
typedef struct schmurtz {
    int f;
    int arg;
}Schmurtz;

int do_ThreadCreate(int f, int arg){
    Thread *newThread = new Thread("newThread");
    AddrSpace *oldSpace = currentThread->space;
    newThread->space = oldSpace;
    Schmurtz schmurtz= (Schmurtz) malloc(sizeof(int)*2);
    schmurtz.f = f;
    schmurtz.arg = arg;
    //TODO:init the stack
    //newThread->Start(StartUserThread, schmurtz);
    return -1;
}
#endif