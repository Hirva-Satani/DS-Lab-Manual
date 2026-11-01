// CIRCULAR LINKED LIST
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *head = NULL;

struct Node* createNode(int info)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->info = info;
    newNode->link = NULL;

    return newNode;
}

void insertFront(int info)
{
    struct Node *newNode,*temp;

    newNode = createNode(info);

    if(head == NULL)
    {
        newNode->link = newNode;
        head = newNode;
        printf("Node inserted at front.\n");
        return;
    }

    temp=head;

    while(temp->link != head)
        temp = temp->link;

    newNode->link = head;
    temp->link = newNode;
    head = newNode;

    printf("Node inserted at front.\n");
}

void insertEnd(int info)
{
    struct Node *newNode,*temp;

    newNode = createNode(info);

    if(head == NULL)
    {
        newNode->link = newNode;
        head = newNode;
        printf("Node inserted at end.\n");
        return;
    }

    temp = head;

    while(temp->link != head)
        temp = temp->link;

    temp->link = newNode;
    newNode->link = head;

    printf("Node inserted at end.\n");
}

void deleteFirst()
{
    struct Node *temp,*del;

    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    // Only one node
    if(head->link == head)
    {
        free(head);
        head = NULL;
        printf("First node deleted.\n");
        return;
    }

    temp = head;

    // Find last node
    while(temp->link != head)
        temp = temp->link;

    del = head;
    head = head->link;
    temp->link = head;

    free(del);

    printf("First node deleted.\n");
}

void deleteLast()
{
    struct Node *temp,*del;

    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    //if only one node
    if(head->link == head)
    {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    temp = head;

    // Find second-last node
    while(temp->link->link != head)
        temp = temp->link;

    del = temp->link;
    temp->link = head;

    free(del);

    printf("Last node deleted.\n");
}

// Delete node from specified position
void deleteAtPosition(int pos)
{
    struct Node *temp,*prev;
    int count = 1;

    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if(pos<=0)
    {
        printf("Invalid position!\n");
        return;
    }

    // Delete first node
    if(pos==1)
    {
        deleteFirst();
        return;
    }

    temp=head;

    while(count<pos && temp->link!=head)
    {
        prev = temp;
        temp = temp->link;
        count++;
    }

    if(count != pos)
    {
        printf("Invalid position!\n");
        return;
    }

    prev->link = temp->link;
    free(temp);

    printf("Node at position %d deleted.\n",pos);
}

// Display circular linked list
void displayList()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Circular Linked List: ");       

    do
    {
        printf("%d -> ",temp->info);
        temp = temp->link;
    }
    while(temp != head);

    printf("(back to head)\n");
}

void main()
{
    int choice,info,pos;

    while(1)
    {
        printf("\n----- CIRCULAR LINKED LIST -----\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete First Node\n");
        printf("4. Delete Last Node\n");
        printf("5. Delete Node from Specified Position\n");
        printf("6. Display List\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter element to insert at front: ");
                scanf("%d",&info);
                insertFront(info);
                break;

            case 2:
                printf("Enter element to insert at end: ");
                scanf("%d",&info);
                insertEnd(info);
                break;

            case 3:
                deleteFirst();
                break;

            case 4:
                deleteLast();
                break;

            case 5:
                printf("Enter position to delete: ");
                scanf("%d",&pos);
                deleteAtPosition(pos);
                break;

            case 6:
                displayList();
                break;

            case 7:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}