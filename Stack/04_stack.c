#include<stdio.h>
#include<stdlib.h>
// Basic definition of stack 
struct stack{
    int size;
    int top;
    char* arr;
};

// Defining the function / method for checking if the list is empty
int isEmpty(struct stack *s){
    if (s->top == -1)
    {
        return 1;
    } else {
        return 0;
    }
    
}

// Defining the function / method for checking if the list is full
int isFull(struct stack * s){
    if (s->top == ((s->size) -1))
    {
        return 1;
    } else {
        return 0;
    }
    
}

// Defining the function for pushing an element on the stack 
int push(struct stack* s, char data){
    if(isFull(s)){
        printf("Error! Stack Overflow.\n ");
        return 0;
    } else {
        s->arr[s->top +1] = data;
        //printf("Pushed %c successfully.\n", data);
        s->top += 1;
        return 1;
    }
}

// Defining the function for poping out an element from the element
void pop(struct stack* s){
    int i = s->top;
    if(isEmpty(s)){
        printf("Error! Stack underflow.\n");
    } else {
        s->top = s->top-1;
        //printf("Popped %c from the stack.\n", s->arr[s->top+1]);
    }
}

// Defining the function for traversal of the stack
int show(struct stack* s){
    if(isEmpty(s)){
        printf("Stack Underflow.\n");
        return 0;
    } else {
        int i = 0;
        while(i <= s->top){
            printf("%c  ", s->arr[s->top -i]);
            i++;
        }
        printf("\n");
        return 1;
    }
}

// Defining the function/method for peek operation
/*int peek(struct stack* sp, int i){
    if(isEmpty(sp) || (sp->top-i < 0)){
        return -1;
    } else {
        return sp->top - i +1;
    }
}*/

char stackTop(struct stack* s){
    if(isEmpty(s)){
        return -1;
    } else
        return s->arr[s->top];
}

char stackBottom(struct stack * s){
    if(isEmpty(s)){
        return -1;
    } else
        return s->arr[0];
}
int main(){
    struct stack* s1;
    s1 = (struct stack*)malloc(sizeof(struct stack));
    s1->size = 50;
    s1->top = -1;
    s1->arr = (char*)malloc((s1->size) * sizeof(char));

    char demo[50] ;
    printf("type expression : ");
    scanf("%s", &demo[0]);
    int i = 0;
    int p_count = 0, pp_count = 0;
    while(demo[i] != '\0'){
        if(demo[i] == ')' ){
            if(s1->top != -1 && s1->arr[s1->top] == '(')
                pop(s1);
            else 
                break;
            pp_count += 1;
        }
        if(demo[i] == ']' ){
            if(s1->top != -1 && s1->arr[s1->top] == '[')
                pop(s1);
            else 
                break;
            pp_count += 1;
        }
        if(demo[i] == '}' ){
            if(s1->top != -1 && s1->arr[s1->top] == '{')
                pop(s1);
            else 
                break;
            pp_count += 1;
        }
        if(demo[i] == '(' ){
            push(s1, '(');
            p_count += 1;
        }
        if(demo[i] == '[' ){
            push(s1, '[');
            p_count += 1;
        }
        if(demo[i] == '{' ){
            push(s1, '{');
            p_count += 1;
        }
        i++;
    }
    if(s1->top == -1 && pp_count == p_count){
        printf("parenthesis matching.\n");
    } else {
        printf("Parenthesis not matching.\n");
    }

    
    return 0;
}