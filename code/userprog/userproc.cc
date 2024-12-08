#ifdef CHANGED

#include "system.h"
#include "synch.h"
#include "utils.h"

void StartUserProc(void* arg){
    if (arg){} // Only to remove warning
    currentThread->space->InitRegisters ();
    currentThread->space->RestoreState ();
    currentThread->stackIndex=0;

    machine->DumpMem ("newProcess.svg");
    machine->Run ();		// jump to the user progam
    ASSERT_MSG (FALSE, "Machine->Run returned???\n");	// machine->Run never returns;
    // the address space exits
    // by doing the syscall "exit"
}

int initNewProcess(const char *filename){
    OpenFile *executable = fileSystem->Open (filename);
    AddrSpace *space;
    Thread *newThread;

    if (executable == NULL)
      {
          SetColor (stdout, ColorRed);
          SetBold (stdout);
          printf ("Unable to open file %s\n", filename);
          ClearColor (stdout);
          return -1;
      }
    newThread = new Thread("KernelThread");
    space = new AddrSpace (executable);
    machine->pageProvider->AddNewProcess();

    newThread->space = space;

    delete executable;		// close file

    newThread->Start(StartUserProc, (void*) NULL);

    return 0;
}

void do_ProcessExit(){
    int i;
    Lock* l;
    DEBUG('s', "[THREAD] Thread exit\n");
    machine->pageProvider->RemoveProcess();
    machine->pageProvider->proc->Acquire();
    machine->pageProvider->processWait->Signal(machine->pageProvider->proc);
    int remaining = machine->pageProvider->RemainingRunningProcess();
    for(i =0; i<MAX_THREADS; i++){
        DEBUG('s', "I= %d\n", i);
        if(currentThread->space->aliveThreads[i] != NULL){
             removeThreadFromLockQueue(consoledriver->GetGetStringLock(),currentThread->space->aliveThreads[i]);
             removeThreadFromLockQueue(consoledriver->GetPutStringLock(),currentThread->space->aliveThreads[i]);
           }
        if (i != currentThread->stackIndex)
            if (currentThread->space->aliveThreads[i] != NULL){
                DEBUG('s',"thread alive waiting to be killed\n");
                l = consoledriver->GetPutStringLock();
                if (l->getOwner() == currentThread->space->aliveThreads[i]){
                    DEBUG('s',"force release putstring\n");
                    consoledriver->GetPutStringLock()->ForceRelease();
                }else if ( consoledriver->GetGetStringLock()->getOwner()== currentThread->space->aliveThreads[i]){
                     DEBUG('s',"force release getstring\n");
                     consoledriver->GetGetStringLock()->ForceRelease();
                }
                delete currentThread->space->aliveThreads[i];
            }

    }
    delete currentThread->space;
    if (!remaining ){
        DEBUG('s', "[THREAD] Last thread exited, power down\n");
        interrupt->Powerdown();
    }
    currentThread->Finish();
}


#endif