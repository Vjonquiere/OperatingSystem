#ifdef CHANGED
#include "syscall.h"

int
main ()
{
    char buffer[64];
    while(1){
        PutString("[SHELL]:$");
        GetString(buffer, 64);
        if (ForkExec(buffer) == 0) Wait();
        buffer[0] = '\0';
    }
}
#endif