#ifdef CHANGED
#include "system.h"

unsigned copyStringFromMachine(int from, char *to, unsigned size){
    int* tmp = (int*) malloc(sizeof(int));
    if(tmp == NULL){
        DEBUG('t',"[ERROR] tried to copyStringFromMachine with a null pointer");
        return 0;

    }
    unsigned int i;
    for( i=0; i< size; i++){ //on ne note que size-1 char, le dernier est le '/0
        if(i == size-1){
            *to = '\0';
        }else{
            machine -> ReadMem(from, sizeof(char),tmp);
            *to = *tmp;
            to++;
            from++;
        }
        if(*tmp == '\0'){
            break;
        }
    }
    free(tmp);
    return i;
}

unsigned copyStringToMachine(char* from, int to, unsigned size){
    if(from == NULL){
        DEBUG('t',"[ERROR] tried to copyStringFromMachine with a null pointer");
        return 0;
    }
    unsigned int i;
    for( i=0; i< size; i++){
        if(i == size-1){
            machine->WriteMem(to, 1, '\0');
        }else{
            machine->WriteMem(to, 1, *from);
            to++;
            from++;
        }
    }
    return i;
}

void copyIntToMachine(int* from, int to){
    if (from == NULL){
        DEBUG('t',"[ERROR] tried to copy a NULL int");
        return;
    }
    machine->WriteMem(to, sizeof(int), *from);
}

#endif