#ifdef CHANGED

#ifndef PAGEPROVIDER_H
#define PAGEPROVIDER_H

#include "bitmap.h"
class Lock;


class PageProvider:public dontcopythis
{
    public:
        PageProvider(int numberPages, int sizePage, char* mainMemory);
        ~PageProvider();
        int GetEmptyPage();
        int GetRandomEmptyPage();
        int ReleasePage(int numPage);
        unsigned NumAvailPage();
        void AddNewProcess();
        void RemoveProcess();
        bool RemainingRunningProcess();
        int RemainingProcess();

    private:
        BitMap* pageBitmap;
        Lock*  mutex;
        int pageSize;
        char* memory;
        int pageCount;
        unsigned int remainingProcess;
};

#endif // PAGEPROVIDER_H

#endif // CHANGED