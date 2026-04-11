struct arrayList{
    int* arr;
    int* lastIndex;
    int* totalSize;
};
struct arrayList* al_create();
int al_size(struct arrayList *list);
void al_add(int value,struct arrayList *list);
int al_get(int index,struct arrayList *list);
void al_remove(int index,struct arrayList *list);
void al_freeList(struct arrayList *list);
