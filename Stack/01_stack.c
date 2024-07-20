#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int* arr;
};

int isEmpty(struct stack *s){
    if (s->top == -1)
    {
        return 1;
    } else {
        return 0;
    }
    
}
 int isFull(struct stack * s){
    if (s->top == (s->size -1))
    {
        return 1;
    } else {
        return 0;
    }
    
 }


int main(){
    struct stack *s1;
    s1 = (struct stack*)malloc(sizeof(struct stack));
    s1->size = 10;
    s1->top = -1;
    s1->arr = (int*)malloc(10 * sizeof(int));
    if(isEmpty(s1)){
        printf("The stack is empty.\n");
    } else {
        printf("The stack is not empty.\n");
    }

    return 0;
}