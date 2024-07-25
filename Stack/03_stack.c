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
    } else {
        free(p);
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
        top = p;
        return top;
    }

}

// Method for popping out the element from the stack
struct node* pop(struct node* top){
    if(top == NULL){
        return top;
    } else {
        printf("Popped %d from the stack.\n", top->data);
        if(top == NULL){
            return top;
        } else {
            top = top->next;
            return top;
        }
    }
}
int main(){
    struct node* top = NULL;
    top = push(top, 56);
    top = push(top, 6);
    top = push(top, 5);
    printf("\n %d\n ", top->data);
    int res = 1;
    while(res != 0){
        top = pop(top);
        if(top == NULL)
            res = 0;
    }
    printf("Stack Underflow.\n");

    return 0;
}