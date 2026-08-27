#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define size 20
int stack[size];
int top = -1;

void push(int x)
{
    if (top >= 10)
    {
        printf("Stack Overflow");
        return;
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

int pop()
{
    if (top < 0)
    {
        printf("Stack Underflow");
        return 0;
    }
    top--;
    return (stack[top + 1]);
}

void reverse(char expr[]) {
    int len = strlen(expr);
    for (int i = 0; i < len / 2; i++) {
        char temp = expr[i];
        expr[i] = expr[len - i - 1];
        expr[len - i - 1] = temp;
    }
}
void evalprefix(char prefix[])
{
    int i;
    for (i = 0; i < strlen(prefix); i++)
    {
        if (isdigit(prefix[i]))
            push(prefix[i] - '0');
        else
        {
            int operand1 = pop();
            int operand2 = pop();
            switch (prefix[i])
            {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
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
    char prefix[20];
    printf("Enter a prefix expression :");
    scanf("%s", prefix);
    reverse(prefix);
    evalprefix(prefix);
    printf("Answer : %d", pop());
}