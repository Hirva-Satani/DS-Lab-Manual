#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *top=NULL;

void push(int value)
{
    struct Node *newNode;

    newNode=(struct Node*)malloc(sizeof(struct Node));

    if(newNode==NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    newNode->info=value;
    newNode->link=top;
    top=newNode;

    printf("%d pushed into stack\n",value);
}

void pop()
{
    struct Node *temp;

    if(top==NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp=top;
    printf("%d popped from stack\n",top->info);
    top=top->link;
    free(temp);
}

void display()
{
    struct Node *temp;
    if(top==NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    temp=top;

    printf("Stack: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->info);
        temp=temp->link;
    }

    printf("\n");
}

int main()
{
    int choice,value;

    while(1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}