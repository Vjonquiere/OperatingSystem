#ifdef CHANGED
#include "system.h"
typedef struct schmurtz_t {
    int f;
    int arg;
}Schmurtz;


static void StartUserThread(void *schmurtz){
    for (int i = 0; i < NumTotalRegs; i++)
        machine->WriteRegister (i, 0);
    Schmurtz *s = (Schmurtz*) schmurtz;
    machine->WriteRegister(4,s->arg);
    DEBUG('s', "Initializing arg in reg 4\n");
    machine->WriteRegister(PCReg,s->f);
    DEBUG('s', "Initializing f in PCReg\n");
    machine->WriteRegister (NextPCReg, machine->ReadRegister(PCReg) + 4);
    DEBUG('s', "Initializing NextPCReg\n");

    machine->WriteRegister (StackReg,currentThread->space->AllocateUserStack());
    DEBUG ('s', "Initializing stack register to 0x%x\n",
           (currentThread->space->NumPages()) * PageSize - 256);
    free(schmurtz);

    machine->Run();

}

int do_ThreadCreate(int f, int arg){
    Thread *newThread = new Thread("newThread");
    AddrSpace *oldSpace = currentThread->space;
    newThread->space = oldSpace;
    Schmurtz *schmurtz= (Schmurtz*) malloc(sizeof(Schmurtz));
    schmurtz->f = f;
    schmurtz->arg = arg;
  
    newThread->Start(StartUserThread, schmurtz);
    return -1;
}

#endif