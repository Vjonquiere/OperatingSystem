#ifdef CHANGED
#include "syscall.h"
#include "limits.h"
int
main()
{
PutInt(12);
PutInt(0);
PutInt(-1);
PutInt(INT_MAX);
PutInt(INT_MIN);
return 1;
}
#endif
/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -x test/putint

To test our new syscall PutInt.
This program tests classic values like 12, 0, -1 to see if the system call works on non-stress values.
But some values may be issues like INT_MAX or INT_MIN, which are as named, the C max and min value for int.
*/