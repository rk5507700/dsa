#include<stdio.h>
#include<stdlib.h>

/*
Graph
0         1
 \       /
  \     /
   \   /
    \ /
     2
    /
   /
   5 ----4
    \    |
     \   |
      \  |
       \ |
        3

*/

struct node{
    int size;
    int front;
    int rear;
    int* arr;
};

int isEmpty(struct node* q){
    if(q->front > q->rear)
        return 1;
    else 
        return 0;
}

void enqueue(struct node* q, int data){
    q->rear += 1;
    q->arr[q->rear] = data;
    if(q->front == -1)
        q->front = 0;
}

int dequeue(struct node* q){
    if(isEmpty(q))
        return -1;
    else {
        int i = q->arr[q->front];
        q->arr[q->front] = '\0';
        q->front += 1;
        return i;
    }
}

int main(int argc, char const *argv[])
{
    struct node* q;
    q = (struct node*)malloc(sizeof(struct node));
    q->size = 400;
    q->rear = -1;
    q->front = -1;
    q->arr = (int*)malloc((q->size)*sizeof(int));
    
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };
    int i = 2;
    // printf("%d", i);
    visited[i] = 1;
    enqueue(q, i);
    // printf("%d", dequeue(q));
    while(!isEmpty(q)){
        int node = dequeue(q);
        printf("%d ", node);
        for(int j = 0; j < 7; j++){
            if(a[node][j] == 1 && visited[j] == 0){
                enqueue(q, j);
                // printf("%d", j);
                visited[j] = 1;
                // count += 1;
            }
        }
    }
    
    return 0;
}
