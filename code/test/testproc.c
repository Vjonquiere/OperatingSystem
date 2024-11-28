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

int main()
{
ForkExec("test/threadloop");
//ForkExec("test/putchar");
ForkExec("test/getchar");
 return 0;
}

#endif