#include <stdio.h>

#define N 100

char S[N];
int top = -1;

void push(char x)
{
    if (top >= N - 1)
    {
        printf("Stack Overflow");
        return;
    }

    top++;
    S[top] = x;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
        return '\0';
    }

    top--;
    return S[top + 1];
}


int isVowel(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' ||
        x == 'o' || x == 'u')
    {
        return 1;
    }

    return 0;
}

void reverseStack()
{
    char temp[N];
    int t = -1;

    // Pops all elements
    while (top != -1)
    {
        temp[++t] = pop();
    }

    // Pushes them back in the same order
    // reverse logic
    for (int i = 0; i <= t; i++)
    {
        push(temp[i]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack Empty.");
        return;
    }

    for (int i=0;i<=top;i++)
    {
        printf("%c", S[i]);
    }
}

void main()
{
    int T, n;
    char str[N];

    printf("Enter number of test cases: ");
    scanf("%d", &T);

    while (T--)
    {
        top = -1;

        printf("Enter length of string: ");
        scanf("%d", &n);

        printf("Enter string: ");
        scanf("%s", str);

        for (int i=0;i<n;i++)
        {
            if (isVowel(str[i]))
            {
                reverseStack();
                push(str[i]);
            }
            else
            {
                push(str[i]);
            }
        }

        printf("Final string: ");
        display();
        printf("\n");
    }
}