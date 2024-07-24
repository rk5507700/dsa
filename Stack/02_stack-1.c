#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

// Empty operation for stack
int isEmpty(struct node* top){
    if(top == NULL){
        return 1;
    } else {

        return 0;
    }
}

int isFull(struct node* top){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if(p == NULL){
        return 1;
    } else {
        free(p);
        return 0;
    }
}

// Push method for stack
struct node* push(struct node* top, int data){
    struct node* p = (struct node*)malloc(sizeof(struct node));;
    if(top == NULL){
        return NULL;
    } else{
        p->next = top;
        p->data = data;
        return p;
    }


}

// Pop method for stack

struct node* pop(struct node* top){
    struct node* p = NULL;
    if(isEmpty(top)){
        printf("Stack underflow.\n");
        return NULL;

    } else {
        p = top;
        printf("Popped out %d from stack.\n", p->data);
        top = top->next;
        free(p);
        printf("%d\n", top->data);
        return top;
    }
}

// Peek method for stack
int peek(struct node* top, int pos){
    struct node* p = top;
    for(int i = 0; i<pos-1 && p != NULL; i++){
        p = p->next;
    }
    if(p != NULL){
        int i = p->data;
        return i;
    }
    else {
        return -1;
    }
}

int main(){
    struct node* top = NULL;
    int j;
    printf("\n\n\n\n");
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 23);
    top = push(top, 24);
    printf("%d\n", top->data);

    /*
    int i = 0;
    while(top != NULL){
        if(top == NULL){
            printf("Stack underflow.\n");
        } else
            top = pop(top);
    }
    */
   int i = 3;

    printf("Value at position %d is : %d", i, peek(top, i));
    printf("\n\n");
    return 0;
    
}