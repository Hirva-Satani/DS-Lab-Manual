#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

void display(struct node *head){
    while(head!=NULL){
        printf("%d -> ",head->info);
        head=head->link;
    }
    printf("NULL");
}

void removeDuplicates(struct node *head){
    struct node *temp,*current;

    current=head;

    while(current!=NULL){
        temp=current;

        while(temp->link!=NULL){
            if(current->info==temp->link->info){
                temp->link=temp->link->link;
            }
            else{
                temp=temp->link;
            }
        }

        current=current->link;
    }
}

void main(){
    struct node *head=NULL,*newnode,*temp;
    int n,x;

    printf("Enter number of nodes:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);

        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->info=x;
        newnode->link=NULL;

        if(head==NULL){
            head=newnode;
        }
        else{
            temp=head;

            while(temp->link!=NULL)
                temp=temp->link;

            temp->link=newnode;
        }
    }

    printf("Original Linked List:\n");
    display(head);

    removeDuplicates(head);

    printf("\nLinked List after removing duplicates:\n");
    display(head);
}