// Stack using Linked lists
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prv;
    struct node* next;
};

int isEmpty(struct node * top){
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
        return 0;
    }
}

struct node* push(struct node*top, int data){
    struct node * top1 = NULL;
    if(isFull(top)){
        printf("Stack overflow.\n");
        return top;
    } else {
        top1 = (struct node*)malloc(sizeof(struct node));
        top1->data = data;
        top1->prv = top;
        top1->next = NULL;
        return top1;
    }
}

int main(){
    struct node* top = NULL;
    int i  = 0;
    while(i<10){
        int n;
        printf("Enter a data : ");
        scanf("%d", &n);
        top = push(top, n);
        printf("%d\n", top->data);
        i++;
    }

    return 0;
    

}