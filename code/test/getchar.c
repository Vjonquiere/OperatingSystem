#ifdef CHANGED
#include "syscall.h"

int
main()
{
PutChar(GetChar());
return 1;
}
#endif

/*
To lauch the test, go in the code folder and execute the makefile with the command make.

To run several tests,we made a list of commands like:
printf "something" | ./userprog/nachos -x test/getchar

You just need to run ./test/getCharTests.sh in code/ folder to see tested values.
This script tests values that could be seen as 'sensitive' (for example EOF or '\n') and classic data (formal char like 'a' or 't')

You can also test manually:
Execute the following command:
./userprog/nachos -x test/getchar

To test the GetChar system call, this program wait for a user input.
When written, just press CTRL+D to close Standard input.
The char is printed in the console.

*/