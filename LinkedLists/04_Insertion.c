#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void show(struct node* a){
    while(a != NULL){
        printf("%d ", a->data);
        a = a->next;
    }
    printf("\n");
}
// Case 1: Inserting the element/ node at the start
struct node* InsertAtBeginning(struct node* head){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = 0;
    ptr->next = head;
    head = ptr;
    return head;
}

//Case 2: Inserting at an index
void InsertAtIndex(struct node * head, int index){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = (struct node*)malloc(sizeof(struct node));
    ptr->data = 0;
    int i = 0;
    while (i < index-1){
        p = head;
        head = head->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
}

// Case 3: Inserting at the end of list
void InsertAtEnd(struct node* head){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = (struct node*)malloc(sizeof(struct node));
    while(head != NULL){
        p = head;
        head = head->next;
    }
    ptr->data = 99;
    p->next = ptr;
}


int main(){
    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;
    printf("Original List : ");
    show(head);
    head = InsertAtBeginning(head);
    printf("Inserted at the beginning : ");
    show(head);
    InsertAtIndex(head, 3);
    printf("Inserted at index 3 : ");
    show(head);

    printf("Inserted at the end : ");
    InsertAtEnd(head);
    show(head);

    return 0;
}
