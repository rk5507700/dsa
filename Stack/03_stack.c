#include<stdio.h>
#include<stdlib.h>
// Node of the stack
struct node{
    int data;
    struct node* next;
};

// Method for checking if stack is empty
int isEmpty(struct node* top){
    if(top == NULL){
        return 1;
    } else {
        return 0;
    }
}

// Method for checking if stack is full
int isFull(){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if(p == NULL){
        return 1;
        free(p);
    } else {
        return 0;
    }
}

// Method for pushing an element onto the stack
struct node* push(struct node* top, int data){
    if(isFull()){
        return top;
    } else {
        struct node* p = (struct node*)malloc(sizeof(struct node));
        p->data = data;
        p->next = top;
        return p;
    }

}

// Method for popping out the element from the stack
struct node* pop(struct node* top){
    if(isEmpty(top)){
        return top;
    } else {
        printf("Popped %d from the stack.\n", top->data);
        top = top->next;
        return top;
    }
}
int main(){
    struct node* top;
    top = push(top, 56);
    printf("\n %d\n ", top->data);
    top = pop(top);
    printf("%d", top->data);

    return 0;
}