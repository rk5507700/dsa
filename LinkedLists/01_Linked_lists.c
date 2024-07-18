#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data1;
    int data2;
    struct Node* next;
};

void listTraversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("%d %d ", ptr->data1, ptr->data2);
        ptr = ptr->next;
    }
    
}



int main(){
    struct Node * head;
    struct Node* second;
    struct Node* third;


    //Allocate memory for the nodes in linked lists in heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    // Connecting the links
    head->data1 = 7;
    head->data2 = 8;
    head->next = second;

    //
    second->next = third;
    second->data1 = 9;
    second->data2 = 10;
    //
    third->data1 = 11;
    third->data2 = 12;
    third->next = NULL;
    listTraversal(head);
    
    return 0;
}