#ifdef CHANGED

#include "synch.h"
#include "pageprovider.h"

PageProvider::PageProvider(int numberPages, int sizePage, char* mainMemory){
    pageBitmap = new BitMap(numberPages);
    mutex= new Lock("PageProviderLock");
    pageSize = sizePage;
    memory = mainMemory;
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


#endif