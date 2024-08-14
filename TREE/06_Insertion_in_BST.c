/*
Insertion in Binary search tree

                8
               / \
              3   10
             / \    \
            /   \    \
           /     \    \
          1     6      14
               / \     /
              /   \   / 
            (4)   (7)(13)
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    return p;
}

void BSTtraversal(struct node *root)
{
    if(root != NULL){
        BSTtraversal(root->left);
        printf("%d ", root->data);
        BSTtraversal(root->right);
    }
}

void Insert(struct node* root, int data){
    if(root != NULL){
        if(root->data == data){
            printf("Data already exists.\n");
        } else if(data > root->data){
            if(root->right == NULL){
                struct node* p = (struct node*)malloc(sizeof(struct node));
                p->data = data;
                root->right = p;
            } else {
                Insert(root->right, data);
            }
        } else {
            if(root->left == NULL){
                struct node* p = (struct node*)malloc(sizeof(struct node));
                p->data = data;
                root->left = p;
            } else {
                Insert(root->left, data);
            }
        }
    }
}

int main()
{
    struct node *root = createNode(8);
    struct node *level2_left = createNode(3);
    root->left = level2_left;

    struct node *p3 = createNode(1);
    level2_left->left = p3;

    struct node *p4 = createNode(6);
    level2_left->right = p4;

    struct node *p5 = createNode(4);
    p4->left = p5;

    struct node *p6 = createNode(7);
    p4->right = p6;

    struct node *level2_right = createNode(10);
    root->right = level2_right;

    struct node *p7 = createNode(14);
    level2_right->left = NULL;
    level2_right->right = p7;

    struct node *p8 = createNode(13);
    p7->left = p8;

    BSTtraversal(root);
    printf("Enter the element to insert: ");
    int Insert_element;
    scanf("%d", &Insert_element);

    Insert(root, 6);
    printf("\n");
    BSTtraversal(root);

    return 0;
}