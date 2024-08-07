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

int main(){
    struct binary_node* root = createNode(11, NULL);
    struct binary_node* p1_right = createNode(10, root);
    struct binary_node* p1_left = createNode(8, root);
    return 0;
}
