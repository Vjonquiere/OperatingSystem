#ifdef CHANGED
#include "syscall.h"

int
main()
{
char s[20];
GetString(s, 20);
PutString(s);
return 1;
}
#endif
/*
To lauch the test, go in the code folder and execute the makefile with the command make.

To run several tests we made a list commands like:
printf "something" | ./userprog/nachos -x test/getstring

You just need to run ./test/getStringTest.sh in code/ folder to see tested values.
This script tests the system call on several strings.


You can also test manually:
Execute the following command:
./userprog/nachos -x test/getstring

To test the GetString system call, this program wait for a user input.
When your string is written, just press CTRL+D to close Standard input.
The char is printed in the console.

*/