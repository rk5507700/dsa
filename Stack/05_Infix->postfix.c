#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char* arr;
};

void push(struct stack* stack, char data){
    if(stack->top == (stack->size-1)){
        printf("stack overflow.\n");
    } else {
        stack->top += 1;
        stack->arr[stack->top] = data;
    }
}

void pop(struct stack* stack){
    if(stack->top == -1){
        printf("Stack underflow.\n");
    } else {
        printf("Popped %d from the stack.\n", stack->arr[stack->top]);
        stack->top -= 1;
    }
}

int isOperator(char s){
    switch (s)
    {
    case '*':
        return 1;
        break;
    case '/':
        return 1;
        break;
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

int precedence(char c){
    switch (c)
    {
    case '*': return 2;
        /* code */
        break;

    case '/': return 2;
        /* code */
        break;
    
    default: return 1;
        break;
    }
}

int main(){
    struct stack* stack;
    stack = (struct stack*)malloc(sizeof(struct stack));
    stack->size = 20;
    stack->top = -1;
    stack->arr = (char*) malloc((stack->size)*sizeof(char));

    char usr_arr[20];
    char new_arr[20];

    printf("Enter your expression: ");
    scanf("%s\n", &usr_arr[0]);

    int i = 0;
    int j = 0;

    while(usr_arr[i] != '\0'){
        if(!isOperator(usr_arr[i])){
            new_arr[j] = usr_arr[i];
            j++;
        } else {
            if(stack->top == -1){
                push(stack, usr_arr[i]);
            } else {
                if(precedence(usr_arr[i])<= precedence(stack->arr[stack->top])){
                    while(precedence(usr_arr[i])<= precedence(stack->arr[stack->top])){
                        new_arr[j] = stack->arr[stack->top];
                        stack->top -= 1;
                        j++;
                        if(stack->top == -1)
                            break;
                    }
                } else {
                    push(stack, usr_arr[i]);
                }

            }
        }
        i++;
    }
    while(stack->top != -1){
        new_arr[j] = stack->arr[stack->top];
        j++;
        stack->top -= 1;
    }
    printf("%s", new_arr);

    return 0;


}