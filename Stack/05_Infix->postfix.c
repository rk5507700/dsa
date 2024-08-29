#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isOperator(char c)
{
    switch (c)
    {
    case '*':
        return 1;
        break;
    case '/':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '+':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

void push(struct stack *s, char c)
{
    s->arr[s->top + 1] = c;
    s->top += 1;
}

char pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow.\n");
        return '\0';
    }
    else
    {
        char c = s->arr[s->top];
        s->top -= 1;
        return c;
    }
}

int precedence(char c)
{
    switch (c)
    {
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '-':
        return 1;
        break;
    case '+':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

char stackTop(struct stack *s)
{
    if (s->top == -1)
        return '\0';
    else
        return s->arr[s->top];
}

char *inToPos(char *infix)
{
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack->top = -1;
    stack->size = strlen(infix);
    stack->arr = (char *)malloc(stack->size * sizeof(char));
    char *postfix_arr = (char *)malloc((stack->size + 1) * sizeof(char));

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix_arr[j] = infix[i];
            j++;
        }
        else
        {
            while(!(precedence(infix[i]) > precedence(stackTop(stack))))
            {
                postfix_arr[j] = pop(stack);
                j++;
            }
            push(stack, infix[i]);
            
        }
        i++;
    }
    while(stack->top != -1){
        postfix_arr[j] = pop(stack);
    }
    return postfix_arr;
}
int main()
{
    char *arr = (char *)malloc(30 * sizeof(char));
    printf("Enter your expression: ");
    scanf("%s", &arr[0]);
    char* pos = inToPos(arr);
    printf("%s", pos);
    return 0;
}