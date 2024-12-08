#ifdef CHANGED
#include "syscall.h"
int main(){
    ForkExec("test/threadloopprocess");
    ForkExec("test/threadloopprocess");
    return 1;
}
#endif