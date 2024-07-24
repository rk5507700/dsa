#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node* next;

};

struct node* push(struct node* top, char data){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->next = top;
    return p;

}

struct node* pop(struct node* top){
    top = top->next;
    return top;
}

int main(){
    struct node* top;
    char str[50];
 
    scanf("%s", &str[0]);
    int j = 0;
    int i = 0;
    while(str[i] != '\0'){
        printf("%c", str[i]);
        if(top != NULL && str[i] == ')'){
            top = pop(top);
        }
        
        if(str[i] == '('){
            top = push(top, str[i]);
            j++;
        }
        i++;
    }
    if(j != 0 && top == NULL){
        printf("Parenthesis is matching.\n");
    } else {
        printf("Parenthesis Not matching.\n");
    }
    return 0;
}