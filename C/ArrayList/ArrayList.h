struct arrayList{
    int* arr;
    int lastIndex;
};
struct arrayList* create();
void add(int value,struct arrayList *list);
int get(int index,struct arrayList *list);
void remove(int index,struct arrayList *list);
int size(struct arrayList *arrayList);
