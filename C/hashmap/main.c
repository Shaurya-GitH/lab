#include <stdio.h>
#include "hashmap.h"

int main(){
    struct hashmap *map=hm_create();
    hm_put(map,"key1",1);
    hm_put(map,"key2",2);
    hm_put(map,"key3",3);
    printf("key1: %d\n",hm_get(map,"key1"));
    printf("key2: %d\n",hm_get(map,"key2"));
    printf("key3: %d\n",hm_get(map,"key3"));
    hm_put(map,"key1",4);
    printf("key1: %d\n",hm_get(map,"key1"));
    hm_free(map);
    return 0;
}
