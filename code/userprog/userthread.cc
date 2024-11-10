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
    DEBUG('s', "[THREAD] Initializing arg in reg 4\n");
    machine->WriteRegister(PCReg,s->f);
    DEBUG('s', "[THREAD] Initializing f in PCReg : 0x%x \n", machine->ReadRegister(PCReg));
    machine->WriteRegister (NextPCReg, machine->ReadRegister(PCReg) + 4);
    DEBUG('s', "[THREAD] Initializing NextPCReg\n");
    currentThread->stackIndex = s->stackIndex;
    machine->WriteRegister (StackReg,(currentThread->space->NumPages()) * PageSize - 256*s->stackIndex);
    DEBUG ('s', "[THREAD] Initializing stack register to 0x%x\n",
           machine->ReadRegister(StackReg));
    machine->WriteRegister(RetAddrReg, s->exitAddress);
    free(s);
    machine->DumpMem("threads.svg");
    machine->Run();

}

int do_ThreadCreate(int f, int arg, int exitAddress){
    DEBUG('s', "[THREAD] Thread creation began\n");
    int stackIndex =currentThread->space->AllocateUserStack();
    if(stackIndex == -1){
        DEBUG('s', "[THREAD] Thread creation failed (can't allocate a stack)\n");
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
    DEBUG('s', "[THREAD] Thread has been created\n");
    return 0;
}

void do_ThreadExit(){
    DEBUG('s', "[THREAD] Thread exit\n");
    int remaining = currentThread->space->ThreadLeaving();
    if (remaining <= 0){
        DEBUG('s', "[THREAD] Last thread exited, power down\n");
        delete currentThread->space;
        interrupt->Powerdown();
    }
    currentThread->Finish();
}

#endif