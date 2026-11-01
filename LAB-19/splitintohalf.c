// WAP to split a circular linked list into two halves.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

void insertAtFirst(int x, struct Node **first, struct Node **last)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = x;
    if (*first == NULL)
    {
        newNode->link = newNode;//newnode points to itself
        *first = newNode;//it becomes both 1st and last node
        *last = newNode;
    }
    else
    {
        newNode->link = *first;
        (*last)->link = newNode;
        *first = newNode;
    }
}

void display(struct Node *first)
{
    if(first == NULL)
    {
        printf("Your linked list is empty:");
        return;
    }
    struct Node *save = first;
    printf("[");

    do {
        printf("%d ", save->info);
        save = save->link;
    } while (save != first);

    printf("]\n\n");
}


void splitList(struct Node **first,struct Node **last,struct Node **first1,struct Node **last1)
{
    struct Node *ptr1 = *first;// slow
    struct Node *ptr2 = *first; // fast

    while(ptr1->link != *first)
    {
        if(ptr2->link == *first)    //for odd number of elements
        {
            *first1 = ptr1->link;
            *last1 = ptr2;
            (*last1)->link = *first1;
            ptr1->link = *first;
            *last = ptr1;
            break;
        }
        ptr2 = ptr2->link;
        if(ptr2->link == *first)    //for even number of elements
        {
            *first1 = ptr1->link;
            *last1 = ptr2;
            (*last1)->link = *first1;
            ptr1->link = *first;
            *last = ptr1;
            break;
        }
        ptr1 = ptr1->link;
        ptr2 = ptr2->link;
    }
}

int main()
{
    struct Node *first = NULL;
    struct Node *last = NULL;
    struct Node *first1 = NULL;
    struct Node *last1 = NULL;
    int choice;
    while (1)
    {
        printf("Enter 1 for INSERTION AT FIRST POSIION \nEnter 2 for DISPLAY \nEnter 3 to SPLIT LIST\n Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int x;
            printf("Enter a number to be inserted:");
            scanf("%d", &x);
            insertAtFirst(x, &first, &last);
            break;
        }
        case 2:
        {
            int select;
            printf("Enter 1 to display 1st list \nEnter 2 to display 2nd list \n Enter your choice:");
            scanf("%d",&select);
            if(select == 1)
            {
                display(first);
            }
            else
            {
                display(first1);
            }
            break;
        }

        case 3:
        {
            splitList(&first,&last,&first1,&last1);
            
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
}