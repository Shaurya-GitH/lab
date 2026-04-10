struct node { 
    int value;
    struct node *next;
};

struct node* create(int valur);
void append(struct node *head,int value);
void freeList(struct node *head);
