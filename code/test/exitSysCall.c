#ifdef CHANGED
#include "syscall.h"

int
main()
{
return 55;
}
#endif

/*
To lauch the test, go in the code folder and execute the makefile with the command make.

Execute the following command:
./userprog/nachos -x test/exitSysCall

We chose to test with a return value different of -1, 0 or 1 to see it better in the exit recap
The program is correctly exiting without a Halt instruction and you can read the line :

Main return: 55

in your console.

*/