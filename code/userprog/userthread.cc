#ifdef CHANGED
#include "system.h"
typedef struct schmurtz_t {
    int f;
    int arg;
    int stackIndex;
    int exitAddress;
}Schmurtz;


static void StartUserThread(void *schmurtz){
    for (int i = 0; i < NumTotalRegs; i++)
        machine->WriteRegister (i, 0);
    Schmurtz *s = (Schmurtz*) schmurtz;
    machine->WriteRegister(4,s->arg);
    DEBUG('s', "Initializing arg in reg 4\n");
    machine->WriteRegister(PCReg,s->f);
    DEBUG('s', "Initializing f in PCReg : 0x%x \n", machine->ReadRegister(PCReg));
    machine->WriteRegister (NextPCReg, machine->ReadRegister(PCReg) + 4);
    DEBUG('s', "Initializing NextPCReg\n");
    currentThread->stackIndex = s->stackIndex;
    machine->WriteRegister (StackReg,(currentThread->space->NumPages()) * PageSize - 256*s->stackIndex);
    DEBUG ('s', "Initializing stack register to 0x%x\n",
           machine->ReadRegister(StackReg));
    machine->WriteRegister(RetAddrReg, s->exitAddress);
    free(s);
    machine->DumpMem("threads.svg");
    machine->Run();

}

int do_ThreadCreate(int f, int arg, int exitAddress){
    int stackIndex =currentThread->space->AllocateUserStack();
    if(stackIndex == -1){
        return -1;
    }
    Thread *newThread = new Thread("UserThread");
    AddrSpace *oldSpace = currentThread->space;
    newThread->space = oldSpace;
    Schmurtz *schmurtz= (Schmurtz*) malloc(sizeof(Schmurtz));
    schmurtz->f = f;
    schmurtz->arg = arg;
    schmurtz->stackIndex = stackIndex;
    schmurtz->exitAddress = exitAddress;
    newThread->Start(StartUserThread, schmurtz);
    return 0;
}

void do_ThreadExit(){
    int remaining = currentThread->space->ThreadLeaving();
    if (remaining <= 0){
        delete currentThread->space;
        interrupt->Powerdown();
    }
    currentThread->Finish();
}

#endif