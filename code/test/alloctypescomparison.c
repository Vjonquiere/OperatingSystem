#ifdef CHANGED
#include "syscall.h"
int main(){
    ForkExec("test/threadloopprocess");
    ForkExec("test/threadloopprocess");
    return 1;
}
#endif

/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -rs 1234 -x test/alloctypescomparison

This test is only here to compare differente page allocation types. You can set two allocation types:

    1) Random allocation: Just launch the test and watch newProcess.svg to see the result
    2) Classic allocation: un-comment l.142 in addrspace.cc (comment l.143) and watch newProcess.svg to see the result

*/