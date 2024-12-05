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
}
#endif