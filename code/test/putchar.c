#include "syscall.h"
void print(char c, int n)
{
#if 0
int i;
for (i = 0; i < n; i++) {
PutChar(c + i);
}
PutChar('\n');
#endif
}
int
main()
{
print('a',4);
Halt();
}