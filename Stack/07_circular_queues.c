#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int* arr;
};

void enqueue(struct queue* q){
    if((q->rear+1)%q->size == q->front)
        printf("Queue is full.\n");
    else {
        q->rear = (q->rear+1)%q->size;
        printf("Enter the element to queue: ");
        scanf("%d", &(q->arr[q->rear]));
        if(q->arr[q->front] == '\0')
            q->front =(q->front+1)%q->size;
    }
}

void dequeue(struct queue* q){
    if(q->arr[q->front] == '\0' || q->front == -1){
        printf("Queue is empty.\n");
    } else {
        printf("Element %d dequeued.\n", q->arr[q->front]);
        if(q->front == q->rear)
            q->arr[q->front] = '\0';
        else
            q->front =(q->front+1)%q->size;
    }
}

void display(struct queue* q){
    if(q->arr[q->front] == '\0' || q->front == -1){
        printf("Queue is empty.\n");
    } else {
        printf("Element %d is queued at the front.\n", q->arr[q->front]);
    }
}

int main(){
    struct queue* q;
    q = (struct queue*)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    q->size = 5;
    q->arr = (int*)malloc(q->size*sizeof(int));

    printf("1.Enqueue.\n");
    printf("2.Dequeue.\n");
    printf("3.Display.\n");
    printf("4.Exit.\n");

    while(1){
        int choice;
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:enqueue(q); 
                break;
            case 2: dequeue(q); 
                break;
            case 3: display(q); 
                break;
            case 4:exit(0); 
                break;
            default : printf("Invalid input.\n"); 
                break;
        }
    }

    return 0;
}