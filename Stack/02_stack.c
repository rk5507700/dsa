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
    } else 
        return 0;
}

int isFull(struct node* top){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if(p == NULL){
        return 1;
    } else 
        return 0;
}

// Push method for stack
struct node* push(struct node* top, int data){
    struct node*p;
    if(isFull(top)){
        return top;
    } else{
        p = (struct node*)malloc(sizeof(struct node));
        p->next = top;
        p->data = data;
        top = p;
        return top;
    }


}

// Pop method for stack

struct node* pop(struct node* top){
    struct node* p;
    if(isEmpty(top)){
        printf("Stack underflow.\n");
        return top;
    } else {
        p = top;
        printf("Popped out %d from stack.\n", p->data);
        top = top->next;
        free(p);
        return top;
    }
}

int main(){
    struct node* top = NULL;
    printf("\n\n\n\n");
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 23);
    top = push(top, 24);
    printf("%d\n", top->data);
    while(!isEmpty(top)){
        top = pop(top);
        printf("%d\n", top->data);
    }
    printf("\n\n\n\n");
    return 0;
    
}