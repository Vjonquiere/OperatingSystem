#ifdef CHANGED
#include "syscall.h"
#include "vsprintf.h"

    int elements = 0;
    sem_t cons;
    sem_t prod;
    sem_t mutex;


void producer(void* a){

    int i;
    for(i = 0; i<10; i++){
        P(prod);
        P(mutex);
        elements++;
        PutString("producer ");
        PutInt(elements);
        PutString("\n");
        V(mutex);
        V(cons);
    }
    
}

void consumer(void* a){
    int i;
    for(i = 0; i<10; i++){
        P(cons);
        P(mutex);
        elements--;
        PutString("consumer ");
        PutInt(elements);
        PutString("\n");
        V(mutex);
        V(prod);
    }
}

int main(void){
    printf("producer consumer problem\n");
    cons = SemaphoreCreate(0);
    prod = SemaphoreCreate(5);
    mutex = SemaphoreCreate(1);

    ThreadCreate(producer, (void*) 'A');
    ThreadCreate(consumer, (void*) 'X');

    ThreadExit();
    return 0;
}
#endif

/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -rs 1234 -x test/semaphores

To test the user semaphores, we have implemented a producer consumer problem using the code in the slides.
We can have at most 5 elements at the same time
Our implementation supports only one producer and one consumer. We have decided
to have a counter instead of a queue as shown in class, due to a lack of implmentation of queues
in user space. To safely interract with this counter, we must make the incrementation and decrementation
exclusive, so that they don't have access to it at the same time.


We don't know the problem for now but with printf in the loops it doesn't work
so we used several PutString and PutInt.
*/