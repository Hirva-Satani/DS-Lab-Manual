#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include<math.h>
#define size 20
int stack[size];
int top=-1;

void push(int x){
    if(top>=10){
        printf("Stack Overflow");
        return;
    }
    else{
        top++;
        stack[top]=x;
    }
}

int pop(){
    if(top<0){
        printf("Stack Underflow");
        return 0;
    }
    top--;
    return(stack[top+1]);
}

void evalpostfix(char postfix[]){
    int i;
    for(i=0; i<strlen(postfix);i++){
        if(isdigit(postfix[i]))
            push(postfix[i] - '0');
        else{
            int operand2 = pop();
            int operand1 = pop();
            switch(postfix[i]){
                case '+':
                push(operand1 + operand2);
                break;
                case '-':
                push(operand1 - operand2);
                break;
                case '*':
                push(operand1 * operand2);
                break;
                case '%':
                push(operand1 % operand2);
                break;
                case '/':
                push(operand1 / operand2);
                break;
                case '^':
                push((int)pow(operand1, operand2));
            }
        }
    }
    
}

void main(){
    char postfix[20];
    printf("Enter a postfix expression :");
    scanf("%s",postfix);
    evalpostfix(postfix);
    printf("Answer : %d",pop());
}