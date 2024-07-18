#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data1;
    struct Node* next;
};

void listTraversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("%d ", ptr->data1);
        ptr = ptr->next;
    }
    
}

struct Node* IndexDeletion(struct Node* head){
    struct Node *p = head;
    head = p->next;
    free(p);
    return(head);

}

void my_input(int* a,int* b){
    scanf("%d %d", a, b);
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
    head->next = second;

    //
    second->next = third;
    second->data1 = 9;
    //
    third->data1 = 11;
    third->next = NULL;
    listTraversal(head);

    //setAtBeginning(ptr, head);
    //head = ptr;
    head = IndexDeletion(head);
    printf("\n");

    listTraversal(head);
    
    return 0;
}