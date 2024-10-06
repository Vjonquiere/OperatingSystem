#include "syscall.h"

int
main()
{
int a;
GetInt(&a);
PutInt(a);
return 1;
}

/*
To lauch the test, go in the code folder and execute the makefile with the command make.

To run several tests we made a list commands like:
printf "your int" | ./userprog/nachos -x test/getint

You just need to run ./test/getIntTest.sh in code/ folder to see tested values.
This script tests the system call on several integers.


You can also test manually:
Execute the following command:
./userprog/nachos -x test/getint

To test the GetInt system call, this program wait for a user input.
When your int is written, just press CTRL+D to close Standard input.
The int is printed in the console with PutInt.

*/