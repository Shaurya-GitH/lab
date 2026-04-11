#include "ArrayList.h"
#include <stdlib.h>

struct arrayList* al_create(){
    struct arrayList* list=malloc(sizeof(struct arrayList));
    list->arr=malloc(10*sizeof(int));
    list->lastIndex=malloc(sizeof(int));
    *list->lastIndex=-1;
    list->totalSize=malloc(sizeof(int));
    *list->totalSize=10;
    return list;
}

int al_size(struct arrayList *list){
    return *list->lastIndex+1;
}

void al_add(int value,struct arrayList *list){
    if(*list->lastIndex>(*list->totalSize)/2){
        *list->totalSize+=5;
        list->arr=realloc(list->arr,*list->totalSize*sizeof(int));
    }
    (*list->lastIndex)++;
    list->arr[*list->lastIndex]=value;
}

int al_get(int index, struct arrayList *list){
    if(index>*list->lastIndex || index<0){
        return -1;
    }
    return list->arr[index];
}

void al_remove(int index,struct arrayList *list){
    if(index>*list->lastIndex || index<0){
        return;
    }
    for(int i=index;i<(*list->lastIndex);i++) {
        list->arr[i]=list->arr[i+1];
    }
    (*list->lastIndex)--;
    return;
}

void al_freeList(struct arrayList *list){
    free(list->arr);
    free(list->lastIndex);
    free(list->totalSize);
    free(list);
    return;
}

