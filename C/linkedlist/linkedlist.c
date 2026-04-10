#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct node* create(int value){
   struct node *head=malloc(sizeof(struct node)); 
   head->value=value;
   head->next=NULL;
   return head;
}

void append(struct node *head,int value){
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=create(value);
    return;
}

void freeList(struct node *head){
    while(head->next!=NULL){
        struct node *prev=head;
        head=head->next;
        free(prev);
    }
    return;
}
