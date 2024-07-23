#include<stdio.h>
#include<stdlib.h>
// Basic definition of stack 
struct stack{
    int size;
    int top;
    int* arr;
};

// Defining the function / method for checking if the list is empty
int isEmpty(struct stack *s){
    if (s->top == -1)
    {
        return 1;
    } else {
        return 0;
    }
    
}

// Defining the function / method for checking if the list is full
int isFull(struct stack * s){
    if (s->top == ((s->size) -1))
    {
        return 1;
    } else {
        return 0;
    }
    
}

// Defining the function for pushing an element on the stack 
int push(struct stack* s, int data){
    if(isFull(s)){
        printf("Error! Stack Overflow.\n");
        return 0;
    } else {
        s->arr[s->top +1] = data;
        printf("Pushed %d successfully.\n", data);
        s->top += 1;
        return 1;
    }
}

// Defining the function for poping out an element from the element
void pop(struct stack* s){
    int i = s->top;
    if(isEmpty(s)){
        printf("Error! Stack underflow.\n");
    } else {
        s->top = s->top-1;
        printf("Popped %d from the stack.\n", s->arr[s->top+1]);
    }
}

// Defining the function for traversal of the stack
int show(struct stack* s){
    if(isEmpty(s)){
        printf("Sorry! Your list is empty.\n");
        return 0;
    } else {
        int i = 0;
        while(i <= s->top){
            printf("%d  ", s->arr[s->top -i]);
            i++;
        }
        printf("\n");
        return 1;
    }
}

// Defining the function/method for peek operation
/*int peek(struct stack* sp, int i){
    if(isEmpty(sp) || (sp->top-i < 0)){
        return -1;
    } else {
        return sp->top - i +1;
    }
}*/
int main(){
    struct stack *s1;
    s1 = (struct stack*)malloc(sizeof(struct stack));
    s1->size = 5;
    s1->top = -1;
    s1->arr = (int*)malloc(5 * sizeof(int));

    int i = 1;
    while(i != 0){
        printf("Enter the data: ");
        int nana;
        printf("%d : ", s1->top);
        scanf("%d", &nana);
        i = push(s1, nana);
    }
    i =1;
    show(s1);
    while(i == 1){
        printf("Do you want to Pop?[Y == 1/Anything else for exit.] : ");
        scanf("%d", &i);
        if(i == 1){
            pop(s1);
            i = show(s1);
        }
    }
    int j = show(s1);
    printf(" The index is %d value is ", j); //s1->arr[j]);
    return 0;
}