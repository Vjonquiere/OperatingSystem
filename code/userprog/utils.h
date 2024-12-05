#ifdef CHANGED

#include "utility.h"
#include "console.h"

class Lock;

unsigned copyStringFromMachine(int from, char *to, unsigned size);
unsigned copyStringToMachine(char* from, int to, unsigned size);
void copyIntToMachine(int* from, int to);

void removeThreadFromLockQueue(Lock* l , Thread* t);
#endif