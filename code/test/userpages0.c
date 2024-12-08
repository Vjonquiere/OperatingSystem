#ifdef CHANGED
#include "syscall.h"
#define THIS "aaa"
#define THAT "bbb"
const int N = 10; // Choose it large enough!

void puts(const char *s)
{
    const char *p; for (p = s; *p != '\0'; p++) PutChar(*p);
}

void f(void *arg)
{
    const char *s = arg;
    int i;
    PutChar('x');
    for (i = 0; i < N; i++)
    puts(s);
    ThreadExit();
}

int main()
{
    ThreadCreate(f, THIS);
    f(THAT);
    ThreadExit();
    return 1;
}

/*
Helping program for testproc.
Code given in the subject.

To see all threads, mutexes, processes debugs labels add `-d s` to the launch command 

*/
#endif