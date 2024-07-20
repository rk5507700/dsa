#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int* arr;
};

void show(struct stack s){
    int i = 0;
    while((*s.arr[i]) != NULL){
        printf("%d", s.arr[i]);
        i++;
    }
    printf("\n");
}

int push(struct stack s, int data){
    s.arr[s.top+1] = data;
    int top = s.top +1;
    return top;
}

int pop(struct stack s){
    int top;
    s.arr[s.top] = NULL;
    top = s.top - 1;
    return top;
}

int main(){
    struct stack s1;
    s1.size = 10;
    s1.top = -1;
    s1.arr = (int*)malloc(s1.size * sizeof(int));
    show(s1);
    s1.top = push(s1, 78);
    show(s1);

    return 0;
}