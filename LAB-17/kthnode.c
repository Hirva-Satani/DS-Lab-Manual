#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *head = NULL; // Global pointer declared

struct Node *createNode(int info)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->link = NULL;
    return newNode;
}

void insertEnd(int info)
{
    struct Node *newNode = createNode(info);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->link != NULL)
        temp = temp->link;

    temp->link = newNode;
}

void display()
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }

    printf("NULL\n");
}

int countNodes()
{
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    return count;
}

void swapKth(int K)
{
    int n=countNodes();

    // If K is more than number of nodes
    if (K>n)
        return;

    // If K-th node from start and end are same, first nd last Kth node are at last only
    if (2*K-1==n)
        return;

    // Find Kth node from start and its previous
    struct Node *x_prev=NULL;
    struct Node *x=head;

    for (int i=1;i<K;i++)
    {
        x_prev=x;
        x=x->link;
    }

    // Find Kth node from end and its previous
    struct Node *y_prev=NULL;
    struct Node *y=head;

    for (int i=1;i<n-K+1;i++)
    {
        y_prev=y;
        y=y->link;
    }

    // Connect previous node of x to y
    if (x_prev)
        x_prev->link=y;
    else
        head=y;

    // Connect previous node of y to x
    if (y_prev)
        y_prev->link = x;
    else
        head = x;

    // Swap links
    struct Node *temp = x->link;
    x->link = y->link;
    y->link = temp;
}

int main()
{
    int n, value, K;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (int i=1;i<=n;i++)
    {
        scanf("%d", &value);
        insertEnd(value);
    }

    printf("Original list: ");
    display();

    printf("Enter K: ");
    scanf("%d", &K);

    swapKth(K);

    printf("Modified list after swapping %dth node: ", K);
    display();

    return 0;
}