#ifdef CHANGED
#include "vsprintf.h"
#include "syscall.h"

int main(){
    printf("Hello World!\n");
    printf("%d %s",200, "test\n");
    printf("Printf %s and working with int %d", "implemented\n", 101);
    printf("printing a char : %c\n", 'c');
    printf("putting d in uppercase %c\n", toupper('d'));
    printf("is a lowercase ? %d\n", islower('a'));
    printf("is A lowercase ? %d\n", islower('A'));
    printf("3 char avec un entier inférieur à 100 : %03d\n", 2);
    printf("lenght of 'azerty':%d\n", strnlen("azerty", 10));
    printf("is '1' a digit ? %d \nis 'a' a digit ? %d\n",isdigit('1'), isdigit('a'));
    printf("is 'A' a hexadecimal digit ? %d \nis 'a' a hexadecimal digit ? %d\n",isxdigit('A'), isxdigit('a'));
    return 1;
}
#endif

/*
To lauch the test, go in the code folder and execute the makefile with the command make.
then execute the following command:
./userprog/nachos -x test/testprintf

To test our function printf, we have called it several times to illustrate the allowed 
operations and formatting.
You can call our function just to print a regular string. You can also add integers in
the middle of our code with %d, add a character with %c ou encore des chaînes de
caractères avec %s. We also can print a number with padding so it can be 3 characters
long if it is lower than 100 with %03d.
We can also use the functions that we have defined in vsprintf like islower, toupper,
strnlen,... They are declared in vsprintf.h
*/