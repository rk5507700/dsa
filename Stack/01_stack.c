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
    if (s->top == ((s->size) -1))
    {
        return 1;
    } else {
        return 0;
    }
    
}

int push(struct stack* s, int data){
    if(isFull(s)){
        printf("Your stack is full.\n");
        return 0;
    } else {
        s->arr[s->top +1] = data;
        s->top += 1;
        return 1;
    }
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

    int i = 1;
    while(i != 0){
        printf("Enter the data: ");
        int nana;
        scanf("%d", &nana);
        i = push(s1, nana);
    }
    show(s1);
    

    return 0;
}