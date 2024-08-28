#include<stdio.h>
#include<stdlib.h>

struct node{
    int size;
    int front;
    int rear;
    int* arr;
};

int isEmpty(struct node* q){
    if(q->front == -1 || q->arr[q->front] == '\0')
        return 1;
    else 
        return 0;
}

void enqueue(struct node* q, int data){
    if((q->rear + 1)%q->size == q->front && q->arr[q->front] != '\0'){
        printf("Queue is full.\n");
    } else {
        if(q->rear == -1){
            q->rear = 0;
            q->arr[q->rear] = data;
            }
        else 
        {
            q->rear = (q->rear+1)%q->size;
            q->arr[q->rear] = data;
        }
        if(q->front == -1)
            q->front = 0;
    }
}

int dequeue(struct node* q){
    if(isEmpty(q))
        return -1;
    else {
        int i = q->arr[q->front];
        q->arr[q->front] = '\0';
        q->front = (q->front + 1)%q->size;
        return i;
    }
}

int main(int argc, char const *argv[])
{
    struct node* q;
    q = (struct node*)malloc(sizeof(struct node));
    q->size = 7;
    q->rear = -1;
    q->front = -1;
    q->arr = (int*)malloc((q->size)*sizeof(int));
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Exit\n");
    while (1)
    {
        int choice, data;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:{ 
            printf("Enter the data: ");
            scanf("%d", &data);
            enqueue(q, data);}
            break;
        case 2:
            {
            data = dequeue(q);
            if(data == -1){
                printf("Queue is empty.\n");
            }
            else {
            printf("Dequeued %d\n", data);
            }
            }
            break;
        case 3: exit(0);
        default:
            break;
        }
    }
    
    return 0;
}
