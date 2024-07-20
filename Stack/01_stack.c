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

void push(struct stack* s, int data){
    
    s->arr[s->top +1] = data;
    s->top += 1;
}

void show(struct stack* s){
    if(isEmpty(s)){
        printf("Sorry! Your list is empty.\n");
    } else {
        int i = 0;
        while(i <= s->top){
            printf("%d", s->arr[i]);
        }
    }
}


int main(){
    struct stack *s1;
    s1 = (struct stack*)malloc(sizeof(struct stack));
    s1->size = 10;
    s1->top = -1;
    s1->arr = (int*)malloc(10 * sizeof(int));
    

    return 0;
}