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
        int ReleasePage(int numPage);
        unsigned NumAvailPage();
    private:
        BitMap* pageBitmap;
        Lock*  mutex;
        int pageSize;
        char* memory;
};

#endif // PAGEPROVIDER_H

#endif // CHANGED