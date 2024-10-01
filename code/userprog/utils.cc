#ifdef CHANGED
#include "system.h"

unsigned copyStringFromMachine(int from, char *to, unsigned size){
    int* tmp = (int*) malloc(sizeof(int));
    if(tmp == NULL){
        DEBUG('t',"tried to copyStringFromMachine with a null pointer");
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

#endif