struct node{
    int value;
    char *key;
    int hash;
    bool filled;
    struct node *next;
};

struct hashmap{
    struct node *nodes;
    int size;
};

struct hashmap* hm_create();
int hm_put(struct hashmap *map,char key[],int value);
int hm_get(struct hashmap *map,char key[]);
void hm_free(struct hashmap *map);
