#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

// Empty operation for stack
int isEmpty(struct node* top){
    if(top == NULL){
        return 1;
    } else {
        
        return 0;
    }
}

int isFull(struct node* top){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if(p == NULL){
        return 1;
    } else {
        free(p);
        return 0;
    }
}

// Push method for stack
struct node* push(struct node* top, int data){
    struct node* p = (struct node*)malloc(sizeof(struct node));;
    if(p == NULL){
        printf("Stack overflow.\n");
        return top;
    } else{
        p->next = top;
        p->data = data;
        return p;
    }


}

// Pop method for stack

struct node* pop(struct node* top){
    struct node* p = NULL;
    if(isEmpty(top)){
        printf("Stack underflow.\n");
        return NULL;

    } else {
        p = top;
        printf("Popped out %d from stack.\n", p->data);
        top = top->next;
        free(p);
        if(top != NULL){

            printf("%d\n", top->data);
        }
        return top;
    }
}


int parenthesis_checking(char* arr, struct node* top){
    for(int i = 0; i<50; i++){

        if((*arr)[i] == ')'){
            if (top == NULL){
                printf("\n");
            } else {
            top = pop(top);
            }
        
        }

        if((*arr)[i] == '('){
            
        }
    }
}

int main(){
    char arr[50];
    scanf("%s", arr[0]);

}