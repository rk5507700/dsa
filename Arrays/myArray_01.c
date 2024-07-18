#include<stdio.h>
#include<stdlib.h>

struct myArray{
    char *ptr;

};

void createArray(struct myArray *a, int n)
{   
    int bn = n;
    char c;
    (a->ptr) = (char*) malloc(n*sizeof(char));
    for(int i = 0; i<bn; i++){
        printf("Enter your element %d", i);
        scanf("%s", &c);
        (a->ptr)[i] = c;
    }
    
}

/*
void setValue(struct myArray *a,int n){
    int c;
    for(int i = 0; i<n; i++){
        scanf("%d", &c);
        (a->ptr)[i] = c;
    }
}
*/

void show(struct myArray *a,int n){
    for(int i = 0; i<n; i++){
        printf("%c\n", (a->ptr)[i]);
    }
}


int main(){
    int n;
    struct myArray arr;
    scanf("%d", &n);
    createArray(&arr, n);
    //setValue(&arr, n);
    show(&arr, n);

    return 0;
}