#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int backInd;
    int size;
    int *arr;
};

void enqueue(struct queue *q)
{
    printf("Enter the enqueue element: ");
    int n;
    scanf("%d", &n);
    q->backInd += 1;
    q->arr[q->backInd] = n;
}

void dequeue(struct queue *q)
{
    if (q->backInd == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        int i = 0;
        printf("Dequued %d .\n", q->arr[0]);
        for (; i < q->backInd; i++)
        {

            q->arr[i] = q->arr[i + 1];
        }
        q->backInd -= 1;
    }
}

void display(struct queue* s){
    if(s->backInd == -1)
        printf("Queue is empty.\n");
    else
        printf("%d queued at the front.\n", s->arr[0]);
}

int main()
{
    struct queue *Q1;
    Q1 = (struct queue *)malloc(sizeof(struct queue));
    Q1->backInd = -1;
    Q1->size = 30;
    Q1->arr = (int *)malloc(Q1->size * sizeof(int));
    printf("1.Enqueue\n");
    printf("2.Dequue\n");
    printf("3.Display\n");
    printf("4.Exit\n");

    while(1){
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enqueue(Q1);
                break;
            case 2:
                dequeue(Q1);
                break;
            case 3:
                display(Q1);
                break;
            case 4:
                exit(0);
                break;
            default: printf("Invalid input.\n");
                break;
        }
    }
    return 0;
}