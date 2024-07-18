//Creating a Linked Lists And defining operations on it

#include<stdio.h>
#include<stdlib.h>

// Defining the structure of Nodes in List
struct Node{
    int data1;
    int data2;
    int data3;
    struct Node *next;
};


// Defining a function for taking input into nodes of list
void setValue(struct Node * head){
    while(head->next != NULL){
        scanf("%d %d %d", &(head->data1), &(head->data2), &(head->data3));
        head = (head->next);
    }

}

void show(struct Node *head){
    while(head->next != NULL){
        printf("%d %d %d ", head->data1, head->data2, head->data3);
        head = head->next;
    }
}

int main(){
    //Declaring the list nodes
    struct Node *head    = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second  = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third   = (struct Node*)malloc(sizeof(struct Node));
    struct Node *fourth  = (struct Node*)malloc(sizeof(struct Node));

    // Connecting the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    // Calling input function
    setValue(head);

    // Listing the output
    show(head);

    return 0;
}