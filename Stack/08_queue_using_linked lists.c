#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prv;
};

void dequeue(struct node* Front){
    if(Front->prv == NULL){
        if(Front->data == '\0')
            printf("Queue is empty.\n");
        else {

            printf("Dequeued %d from queue.\n", Front->data);
            Front->data = '\0';
        }
    } else {
        struct node* p;
        p = Front;
        printf("Dequeued %d from the queue.\n", p->data);
        Front = Front->prv;
        free(p);
    }
}

void enqueue(struct node* Rear){
    int n;
    printf("Enter your element: ");
    scanf("%d", &n);
    if(Rear->data == '\0'){
        Rear->data = n;
    } else {
        struct node* new_r = (struct node*)malloc(sizeof(struct node));
        new_r->data = n;
        Rear->prv = new_r;
        new_r->next = Rear;
        Rear = new_r;
    }

}

void display(struct node* Front){
    if(Front->data == '\0')
        printf("Queue is empty.\n");
    else 
        printf("%d queued at the front.\n", Front->data);
}

int main(){
    struct node* queue;
    queue = (struct node*)malloc(sizeof(struct node));
    struct node* Rear;
    Rear = queue;
    struct node* Front;
    Front = queue;
    printf("1.Enqueue.\n");
    printf("2.Dequeue.\n");
    printf("3.Display.\n");
    printf("4.Exit.\n");
    while (1)
    {
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:enqueue(Rear);
                
                break;
            case 2: dequeue(Front);
                
                break;
            case 3: display(Front);
                
                break;
            case 4: exit(0);
                
                break;
        
        default:
            printf("Invalid input.\n");
            break;
        }
    }
    

    return 0;



}