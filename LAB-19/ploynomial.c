#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff, exp;
    struct node *next;
};

struct node *create(int c, int e)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = c;
    newnode->exp = e;
    newnode->next = NULL;
    return newnode;
}

struct node *insert(struct node *head, int c, int e)
{
    struct node *newnode = create(c, e);

    if (head == NULL)
        return newnode;

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

void sort(struct node *first)
{
    struct node *i, *j;
    for (i = first; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->exp > j->exp)
            {
                int temp = i->coeff;
                i->coeff = j->coeff;
                j->coeff = temp;

                temp = i->exp;
                i->exp = j->exp;
                j->exp = temp;
            }
        }
    }
}

struct node *addPoly(struct node *p1, struct node *p2)
{
    struct node *result = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp == p2->exp)
        {
            result = insert(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp < p2->exp)
        {
            result = insert(result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else
        {
            result = insert(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        result = insert(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        result = insert(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%dx^%d", head->coeff, head->exp);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
}

int main()
{
    struct node *p1 = NULL, *p2 = NULL, *sum = NULL;
    int n, m, c, e, i;

    printf("Enter terms in Polynomial 1: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &c, &e);
        p1 = insert(p1, c, e);
    }

    printf("Enter terms in Polynomial 2: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &c, &e);
        p2 = insert(p2, c, e);
    }

    sort(p1);
    sort(p2);

    sum = addPoly(p1, p2);

    printf("Result = ");
    display(sum);

    return 0;
}

