#ifdef CHANGED

#include "synch.h"
#include "pageprovider.h"

PageProvider::PageProvider(int numberPages, int sizePage, char* mainMemory){
    pageBitmap = new BitMap(numberPages);
    pageCount = numberPages;
    mutex= new Lock("PageProviderLock");
    pageSize = sizePage;
    memory = mainMemory;
    remainingProcess = 1;
}

PageProvider::~PageProvider(){
    delete pageBitmap;
    delete mutex;
}

int PageProvider::GetEmptyPage(){
    mutex->Acquire();
    int pageInMem;
    int index = pageBitmap->Find();
    if(index == -1){
        mutex->Release();
        return -1;
    }
    pageBitmap->Mark(index);
    pageInMem = pageSize*index;
    memset(memory+pageInMem, 0, pageSize);
    mutex->Release();
    return index;

}

int PageProvider::GetRandomEmptyPage(){
    int index = random()%pageCount;
    mutex->Acquire();
    int pageInMem;
    /*if (NumAvailPage() == 0){
        mutex->Release();
        return -1;
    }*/
    while (pageBitmap->Test(index)){
        index = random()%pageCount;
    }
    pageBitmap->Mark(index);
    pageInMem = pageSize*index;
    memset(memory+pageInMem, 0, pageSize);
    mutex->Release();
    return index;

}

int PageProvider::ReleasePage(int numPage){
    mutex->Acquire();
    if( numPage !=-1){
        pageBitmap->Clear(numPage);
        mutex->Release();
        return 0;
    }
    mutex->Release();
    return -1;
}

unsigned PageProvider::NumAvailPage(){
    mutex->Acquire();
    int count = pageBitmap->NumClear();
    mutex->Release();
    return count;
}
void PageProvider::AddNewProcess(){
    mutex->Acquire();
    remainingProcess ++;
    mutex->Release();
}

void PageProvider::RemoveProcess(){
    mutex->Acquire();
    remainingProcess --;
    mutex->Release();
}

bool PageProvider::RemainingRunningProcess(){
    bool remaining;
    mutex->Acquire();
    remaining = remainingProcess !=0;
    mutex->Release();
    return remaining;
}

int PageProvider::RemainingProcess(){
    int remaining;
    mutex->Acquire();
    remaining = remainingProcess;
    mutex->Release();
    return remaining;
}


#endif