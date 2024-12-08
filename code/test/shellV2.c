#ifdef CHANGED
#include "syscall.h"

int
main ()
{
    char buffer[64];
    while(1){
        PutString("[SHELL]:$");
        GetString(buffer, 64);
        if (buffer[0] == 'e' && buffer[1] == '\0') return 1;
        else if (ForkExec(buffer) == 0) Wait();
        buffer[0] = '\0';
    }
}
#endif