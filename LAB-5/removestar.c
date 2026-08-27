#include <stdio.h>
#define size 20

char stack[size];
int top = -1;

void push(char x)
{
    if (top >= size)
    {
        printf("Stack Overflow!!");
        return;
    }
    top++;
    stack[top] = x;
}

char pop()
{
    if (top<0)
    {
        printf("Stack underflow");
        return 0;
    }
    top--;
    return (stack[top+1]);
}

void display(){
    if(top<0){
        printf("Stack Underflow");
        return;
    }
    printf("New string is:");
    for(int i=0;i<=top;i++){
        printf("%c",stack[i]);
    }
    printf("\n");
}


void Remove(char *str){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='*'){
            pop();
        }
        else{
            push(str[i]);
        }
        i++;
    }
    display();
}

void main(){
    char str[20];
    printf("Enter a string:");
    scanf("%s",str);
    Remove(str);
}


