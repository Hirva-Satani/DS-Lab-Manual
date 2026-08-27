#include <stdio.h>

char stack[10];
int top = -1;

void push(char x)
{
    if (top >= 9)
    {
        printf("Stack Overflow!!");
        return;
    }

    top++;
    stack[top] = x;
}

char pop()
{
    if (top < 0)
    {
        return 0;
    }

    top--;
    return stack[top + 1];
}

int Balanced(char *str)
{
    int i = 0;
    top = -1;

    if(str[0]=='\0')
    {
        return 1;
    }

    while (str[i] != '\0')
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(str[i]);
        }

        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (top == -1)
            {
                return 0;
            }

            char ch = pop();

            if (!((str[i]==')' && ch=='(') ||
                  (str[i]=='}' && ch=='{') ||
                  (str[i]==']' && ch=='[')))
            {
                return 0;
            }
        }

        i++;
    }

    if (top == -1)
        return 1;
    else
        return 0;
}

int main()
{
    int testCase,i;

    printf("How many test cases? ");
    scanf("%d", &testCase);

    for (i=0;i<testCase;i++)
    {
        char str[20];

        printf("\nEnter the string: ");
        scanf("%s", str);

        int isBalanced=Balanced(str);

        printf("%d\n",isBalanced);
    }

    return 0;
}