#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    int priority;
    struct Node *link;
};

struct Node *front=NULL;

void enqueue(int value,int p)
{
    struct Node *newNode,*temp;

    newNode=(struct Node*)malloc(sizeof(struct Node));

    if(newNode==NULL)
    {
        printf("Queue Overflow\n");
        return;
    }

    newNode->info=value;
    newNode->priority=p;
    newNode->link=NULL;

    if(front==NULL || p<front->priority)
    {
        newNode->link=front;
        front=newNode;
    }
    else
    {
        temp=front;

        while(temp->link!=NULL && temp->link->priority<=p)
        {
            temp=temp->link;
        }

        newNode->link=temp->link;
        temp->link=newNode;
    }

    printf("%d inserted with priority %d\n",value,p);
}

void dequeue()
{
    struct Node *temp;

    if(front==NULL)
    {
        printf("Priority Queue is empty\n");
        return;
    }
    temp=front;

    printf("%d deleted\n",front->info);
    front=front->link;
    free(temp);
}

void display()
{
    struct Node *temp=front;

    if(front==NULL)
    {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue:\n");

    while(temp!=NULL)
    {
        printf("info = %d, Priority = %d\n",
               temp->info,temp->priority);

        temp=temp->link;
    }
}

int main()
{
    int choice,value,p;

    while(1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);

                printf("Enter priority: ");
                scanf("%d",&p);

                enqueue(value,p);
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