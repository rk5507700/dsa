/*
          4
         / \
        1   2
       / \   \
      5   7   34
     / \
    99 78
  
*/

#include<stdio.h>
#include<stdlib.h>
struct binary_node
{
    int data;
    struct binary_node* right;
    struct binary_node* left;
    struct binary_node* parent;
};

struct binary_node* createNode(int data, struct binary_node* parent){
    struct binary_node* p1;
    p1 = (struct binary_node*)malloc(sizeof(struct binary_node));
    p1->data = data;
    p1->parent = parent;
    p1->left = NULL;
    p1->right = NULL;
    return p1;
}

void InOrder(struct binary_node* root){
    if(root != NULL){
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

int main(){
    struct binary_node* root = createNode(4, NULL);
    struct binary_node* p1_right = createNode(2, root);
    struct binary_node* p1_left = createNode(1, root);
    struct binary_node* p2_right = createNode(7, p1_left);
    struct binary_node* p2_left = createNode(5, p1_left);
    struct binary_node* p3_left = createNode(99, p2_left);
    struct binary_node* p3_right = createNode(78, p2_left);
    struct binary_node* p1_right_right_child = createNode(34, p1_right);
    // struct binary_node* p3_right = createNode(78, p2_left);
    

    root->right = p1_right;
    root->left = p1_left;

    p1_left->right = p2_right;
    p1_left->left = p2_left;

    p2_left->left = p3_left;
    p2_left->right = p3_right;

    p1_right->right = p1_right_right_child;
    InOrder(root);
    return 0;
}
