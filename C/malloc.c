#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    struct car{
        char name[20];
        int year;
    };

    struct car *bmw=malloc(sizeof(struct car));
    strcpy(bmw->name,"bmw");
    bmw->year=2018;
    printf("car name is : %s, and model is %d\n",bmw->name,bmw->year);
    free(bmw);
    return 0;
}
