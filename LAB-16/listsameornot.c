#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *createNode(int info){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->info=info;
    newNode->link=NULL;
    return newNode;
}

struct node *insertEnd(struct node *head,int info){
    struct node *newNode=createNode(info);

    if(head==NULL)
        return newNode;

    struct node *temp=head;

    while(temp->link!=NULL)
        temp=temp->link;

    temp->link=newNode;

    return head;
}

void display(struct node *head){
    while(head!=NULL){
        printf("%d -> ",head->info);
        head=head->link;
    }
    printf("NULL\n");
}

int isSame(struct node *head1,struct node *head2){
    while(head1!=NULL && head2!=NULL){
        if(head1->info!=head2->info)
            return 0;

        head1=head1->link;
        head2=head2->link;
    }

    if(head1==NULL && head2==NULL)
        return 1;

    return 0;
}

void main(){
    struct node *head1=NULL,*head2=NULL;
    int n1,n2,i,x;

    printf("Enter number of nodes in List 1: ");
    scanf("%d",&n1);

    printf("Enter elements of List 1:\n");

    for(i=0;i<n1;i++){
        scanf("%d",&x);
        head1=insertEnd(head1,x);
    }

    printf("Enter number of nodes in List 2: ");
    scanf("%d",&n2);

    printf("Enter elements of List 2:\n");

    for(i=0;i<n2;i++){
        scanf("%d",&x);
        head2=insertEnd(head2,x);
    }

    printf("\nList 1: ");
    display(head1);

    printf("List 2: ");
    display(head2);

    if(isSame(head1,head2))
        printf("Both linked lists are same.\n");
    else
        printf("Both linked lists are not same.\n");
}