// Write a program to reverse a linked list.

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node* link;
};

struct Node* createNode(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    if(!newNode){//it means memory allocation failed
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->info=value;
    newNode->link=NULL;//it is a new node which is not yet connected to other node

    return newNode;
}

struct Node* insertEnd(struct Node* head,int value){
    struct Node* newNode=createNode(value);

    if(head==NULL){
        head=newNode;
        return head;
    }

    struct Node* temp=head;//temp===last node

    while(temp->link!=NULL)
        temp=temp->link;

    temp->link=newNode;//link the last node's link to the new node

    return head;
}

void display(struct Node* head){
    struct Node* temp=head;

    printf("List: ");

    while(temp!=NULL){
        printf("%d -> ",temp->info);
        temp=temp->link;//loop until the end of list
    }

    printf("NULL\n");
}

struct Node* reverseList(struct Node* head){
    struct Node* prev=NULL;
    struct Node* current=head;
    struct Node* link=NULL;

    while(current!=NULL){
        link=current->link;//Store link
        current->link=prev;//Reverse current node's pointer
        prev=current;//Move prev one step ahead
        current=link;//Move current one step ahead
    }

    head=prev;//Update head to new front

    return head;
}

int main(){
    struct Node* head=NULL;
    int n,value;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter %d values:\n",n);

    for(int i=0;i<n;i++){
        scanf("%d",&value);
        head=insertEnd(head,value);
    }

    printf("\nOriginal linked List:\n");
    display(head);

    head=reverseList(head);

    printf("\nReversed linked List:\n");
    display(head);

    return 0;
}