#include "hashmap.h"
#include <stdlib.h>
#include <string.h>

static int hash(char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return (int)hash;
}

struct hashmap* hm_create(){
    struct hashmap *map=malloc(sizeof(struct hashmap));
    map->size=10;
    map->nodes=calloc(map->size,sizeof(struct node));
    return map;
}

int hm_put(struct hashmap *map,char key[],int value){
    int h=hash(key);
    int index=h%map->size;
    if(!(map->nodes[index].filled)){ 
        map->nodes[index].filled=true;
        map->nodes[index].value=value;
        map->nodes[index].key=key;
        map->nodes[index].hash=h;
    }
    else{
        struct node* node=&(map->nodes[index]);
        while(true){
           if(strcmp(key,node->key)==0){
               node->value=value;
               return 0;
           }
           if(node->next==NULL) break;
           node=node->next;
        }
        struct node *newNode=calloc(1,sizeof(struct node));
        newNode->value=value;
        newNode->key=key;
        newNode->filled=true;
        newNode->hash=h;
        node->next=newNode;
    }
    return 0;
}

int hm_get(struct hashmap *map,char key[]){
    int h=hash(key);
    int index=h%map->size;
    struct node* node=&(map->nodes[index]);
    while(node!=NULL){
        if(strcmp(key,node->key)==0) {
            return node->value;
        }
        node=node->next;
    }
    return -1;
}

void hm_free(struct hashmap *map){
    for(int i=0;i<(map->size);i++){
        struct node *head=map->nodes[i].next;
        while(head!=NULL) {
            struct node *prev=head;
            head=head->next;
            free(prev);
        }
    }
    free(map->nodes);
    free(map);
    return;
}
