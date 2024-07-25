#include<stdio.h>
#include<stdlib.h>


struct stack{
    int size;
    int top;
    int* arr;
};

// Full method
int isFull(struct stack* stack){
    if(stack->top == stack->size-1){
        return 1;
    } else {
        return 0;
    }
}

// Empty method
int isEmpty(struct stack* stack){
    if(stack->top == -1)
        return 1;
    else
        return 0;
}

// Pop Method
struct stack* pop(struct stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow.\n");
        return stack;
    }
        
    else {
        printf("Popped %d from the stack.\n", stack->arr[stack->top]);
        stack->top -= 1;
        return stack;
    }
}

// Push method
struct stack* push(struct stack* stack){
    if(isFull(stack)){
        printf("Stack overflow.\n");
        return stack;
    } else {
        int n;
        printf("Enter data: ");
        scanf("%d", &n);
        stack->arr[stack->top+1] = n;
        stack->top += 1;
        return stack;
    }
}

// Show method
void show(struct stack* stack){
    if(isEmpty(stack))
        printf("Stack Underflow.\n");
    else 
        printf("%d\n", stack->arr[stack->top]);
}

int main(){
    struct stack* stack1;
    stack1 = (struct stack*)malloc(sizeof(struct stack));
    stack1->size = 5;
    stack1->top = -1;
    stack1->arr = (int*)malloc(5*sizeof(int));
    
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Show\n");
    printf("4.Exit\n");

    while(1){
        int choice;
        printf("Enter Your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:{
            stack1 = push(stack1);
            break;
        }
        case 2:{
            stack1 = pop(stack1);
            break;
        }
        case 3:{
            show(stack1);
            break;
        }
        case 4:{ 
            exit(0);
            break;
        }
        default:{
            printf("choice Incorrect.\n");
            break;
        }
        }
    }
    return 0;
}