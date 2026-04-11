#include "ArrayList.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    struct arrayList* list=al_create();
    al_add(1,list);
    al_add(2,list);
    al_add(3,list);
    printf("size of list: %d\n",al_size(list));
    printf("first element: %d\n",al_get(0,list));
    printf("second element: %d\n",al_get(1,list));
    al_remove(1,list);
    printf("size of list: %d\n",al_size(list));
    printf("first element: %d\n",al_get(0,list));
    printf("second element: %d\n",al_get(1,list));
    al_freeList(list);
}
