#include <stdio.h>
#include "linkedlist.h"

int main(){
    struct node *head=create(0);
    head->value=5;
    append(head,5);
    struct node *next=head->next;
    printf("%d\n",next->value);
    freeList(head);
    return 0;
}
