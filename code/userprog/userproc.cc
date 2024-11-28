#ifdef CHANGED

#include "system.h"

void StartUserProc(void* arg){
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
    DEBUG('s', "[THREAD] Thread exit\n");
    machine->pageProvider->RemoveProcess();
    int remaining = machine->pageProvider->RemainingRunningProcess();
    for(i =0; i<MAX_THREADS; i++){
        DEBUG('s', "I= %d\n", i);
        if (i != currentThread->stackIndex)
            if (currentThread->space->aliveThreads[i] != NULL)
                delete currentThread->space->aliveThreads[i];
    }
    delete currentThread->space;
    if (!remaining ){
        DEBUG('s', "[THREAD] Last thread exited, power down\n");
        interrupt->Powerdown();
    }
    currentThread->Finish();
}


#endif