#ifdef CHANGED
#include "syscall.h"
#include "vsprintf.h"

void funcThread(void* a){
    char tab[2] = {'X', '\n'};
    tab[0] = (int) a; //Set first char to the given parameter
    PutString(tab);
    //ThreadExit();
}

int main(){
    if (ThreadCreate(funcThread,(void*)'A') == -1)
        printf("Thread A not created\n");
    if (ThreadCreate(funcThread,(void*)'B') == -1)
        printf("Thread B not created\n");
    if (ThreadCreate(funcThread,(void*)'C') == -1)
        printf("Thread C not created\n");
    if (ThreadCreate(funcThread,(void*)'D') == -1)
        printf("Thread D not created\n");
    if (ThreadCreate(funcThread,(void*)'E') == -1)
        printf("Thread E not created\n");

    ThreadExit();
    return 0;
}

/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -rs 1234 -x test/maxthreadcreate

This test creates several threads to see the behaviour if some can't be created 
(because of stack allocation limit). If the program didn't crash and only dipslay
"Thread X not created", the creation and stack allocation are correctly implemented beacause
the program don't allocate a stack to a weird address or higher than the defined stack and only
send the code -1 (not created) to user.

To see all threads, mutexes debugs labels add `-d s` to the launch command 

*/


#endif