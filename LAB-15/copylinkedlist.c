#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *copyList(struct node *head){
    struct node *newHead=NULL;
    struct node *newTemp=NULL;
    struct node *temp=head;

    while(temp!=NULL){
        struct node *newNode=(struct node*)malloc(sizeof(struct node));

        newNode->info=temp->info;
        newNode->link=NULL;

        if(newHead==NULL){
            newHead=newNode;
            newTemp=newNode;
        }
        else{
            newTemp->link=newNode;
            newTemp=newNode;
        }

        temp=temp->link;
    }

    return newHead;
}

void display(struct node *head){
    while(head!=NULL){
        printf("%d -> ",head->info);
        head=head->link;
    }
    printf("NULL\n");
}

int main(){
    struct node *head=NULL;
    struct node *temp=NULL;
    struct node *newHead=NULL;
    int n,i,value;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter value: ");
        scanf("%d",&value);

        struct node *newNode=(struct node*)malloc(sizeof(struct node));
        newNode->info=value;
        newNode->link=NULL;

        if(head==NULL){
            head=newNode;
            temp=newNode;
        }
        else{
            temp->link=newNode;
            temp=newNode;
        }
    }

    printf("\nOriginal Linked List:\n");
    display(head);

    newHead=copyList(head);

    printf("\nCopied Linked List:\n");
    display(newHead);

    return 0;
}