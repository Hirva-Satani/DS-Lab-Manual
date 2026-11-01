#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *front=NULL, *rear=NULL;

void enqueue(int value)
{
    struct Node *newNode;

    newNode=(struct Node *)malloc(sizeof(struct Node));

    if (newNode==NULL)
    {
        printf("Queue Overflow\n");
        return;
    }

    newNode->info=value;

    if (front==NULL)
    {
        front=rear=newNode;
        rear->link=front;
    }
    else
    {
        newNode->link=front;
        rear->link=newNode;
        rear=newNode;
    }

    printf("%d inserted\n", value);
}

void dequeue()
{
    struct Node *temp;

    if (front==NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    if (front==rear)
    {
        printf("%d deleted\n", front->info);
        free(front);
        front=rear=NULL;
    }
    else
    {
        temp = front;
        printf("%d deleted\n", front->info);
        front=front->link;
        rear->link=front;
        free(temp);
    }
}

void display()
{
    struct Node *temp;

    if (front==NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp=front;

    printf("Circular Queue: ");

    do
    {
        printf("%d ",temp->info);
        temp=temp->link;
    } while (temp!=front);

    printf("\n");
}

int main()
{
    int choice,value;

    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
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
}