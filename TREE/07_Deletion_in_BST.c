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

struct node* inOrderPredecessor(struct node* root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node* delete(struct node* root, int data){
    if(root == NULL){
        return NULL;
    } else if (root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    // Search for the node to be deleted
    if(data < root->data){
        root->left = delete(root->left, data);
    }else if(data > root->data){
        root->right = delete(root->right, data);
    }

    // Deletion strategy
    else {
        //when the node is found
        struct node* iPre = inOrderPredecessor(root); 
        if(iPre->right == NULL){
            root->data = root->right->data;
            root->right = delete(root->right, root->right->data);
        } else {
            root->data = iPre->data;
            root->left = delete(root->left, iPre->data);
        }
    }
    return root;
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
    printf("Enter the element to delete: ");
    int Insert_element;
    scanf("%d", &Insert_element);
    delete(root, Insert_element);
    // printf("\n %d \n", root->right->data);
    BSTtraversal(root);

    return 0;
}