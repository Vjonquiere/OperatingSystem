#ifdef CHANGED
#include "syscall.h"


void testSem(void* i){
    sem_t sem =  (sem_t) i;
    P(sem);
    ThreadExit();

}

int main(void){
    sem_t sem = SemaphoreCreate("semaphore1",1);
    ThreadCreate(testSem, (void*) sem);
    P(sem);
    V(sem);
    
    SemaphoreDelete(sem);
    ThreadExit();
    return 0;
}
#endif