// Write a menu driven program to implement following operations on the singly
// linked list.
// • Insert a node at the front of the linked list.
// Insert a node at the end of the linked list.
// • Insert a node by preserving the order of the data of the linked list. (Ordered
// insertion)
// • Display all nodes.
// • Delete the first node of the linked list.
// • Delete the last node of the linked list.
// • Delete a node from specified position of the list.
// • Count the no. of nodes in the linked list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info ;
    struct node *link;
};
struct node *FIRST=NULL;
void insert_front(int x)
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->info=x;
    new->link=FIRST;
    FIRST=new;
}
void insend(int x)
{
    struct node* new;
    new=(struct node *)malloc(sizeof(struct node));
    new->info=x;
    new->link=NULL;

    if(FIRST==NULL)
    {
        FIRST=new;
        return;
    }
    struct node *save;
    save=FIRST;
    while(save->link!=NULL)
    {
        save=save->link;
    }
    save->link=new;
}
void insord(int x)
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->info=x;

    if(FIRST==NULL)
    {
        new->link=NULL;
        FIRST=new;
    }
    else if(new->info <=FIRST->info)
    {
        new->link=FIRST;
        FIRST=new;
    }
    else
    {
        struct node *save;
        save=FIRST;
        while(save->link!=NULL && new->info > save->link->info)
        {
            save=save->link;
        }
        new->link=save->link;
        save->link=new;
    }

}
void display()
{
    if(FIRST==NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *save;
    save=FIRST;
    while(save!=NULL)
    {
        printf("%d ",save->info);
        save=save->link;
    }
    printf("\n");
}
void delete(int x)
{
    struct node * new;
    if(FIRST==NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *save;
    save=FIRST;
    struct node *pred;
    while(save!=NULL && save->info!=x)
    {
        pred=save;
        save=save->link;
    }
    if(save->info!=x)
    {
        printf("Element not found\n");
        return;
    }
    if(save==FIRST)
    {
        FIRST=FIRST->link;
        free(save);
        return;
    }
    else
    {
     pred->link=save->link;
    }
    free(save);
}
void count()
{
    struct node *save;
    save=FIRST;
    int count=0;
    while(save!=NULL)
    {
        count++;
        save=save->link;
    }
    printf("Number of nodes in the list: %d\n", count);
}
void main()
{
    int choice,x;
    while(1)
    {
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert in order\n");
        printf("4. Display\n");
        printf("5. Delete a node\n");
        printf("6. Count nodes\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d",&x);
                insert_front(x);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d",&x);
                insend(x);
                break;
            case 3:
                printf("Enter value to insert in order: ");
                scanf("%d",&x);
                insord(x);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d",&x);
                delete(x);
                break;
            case 6:
                count();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}