#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

int isFull(){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if(p == NULL){
        return 1;
        free(p);
    } else {
        return 0;
    }
}

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

int main(){
    struct node* top;
    top = push(top, 56);
    printf("\n %d\n ", top->data);

    return 0;
}