#ifdef CHANGED
#include "syscall.h"


void funcThread(void* a){
    char buffer[10];
    GetString(buffer, 10);
    PutString(buffer);
}

int main(){
    
    ThreadCreate((void*)&funcThread,(void*)'A');
    ThreadCreate((void*)&funcThread,(void*)'B');
    ThreadExit();
    return 1;
}

/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -rs 1234 -x test/threadstring

This test is the same as test/threadgetchar but with strings.
Show that `PutString` and `GetString` are now protected.
Write your string (<10 chars), press ENTER, see your string is printed (repeat a seconde time)


To see all threads, mutexes debugs labels add `-d s` to the launch command 

*/


#endif