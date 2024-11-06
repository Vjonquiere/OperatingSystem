#ifdef CHANGED
#include "syscall.h"

int main(void){
    sem_t sem = SemaphoreCreate("semaphore1",1);
    V(sem);
    P(sem);
    SemaphoreDelete(sem);
    return 0;
}
#endif