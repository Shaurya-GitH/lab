#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    struct car{
        char name[20];
        int year;
    };

    struct car *kwid=malloc(sizeof(struct car));
    strcpy(kwid->name,"kwid");
    kwid->year=2018;
    printf("car name is : %s, and model is %d\n",kwid->name,kwid->year);
    free(kwid);
    return 0;
}
