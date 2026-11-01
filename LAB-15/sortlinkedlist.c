// Write a program to sort elements of a linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *createNode(int info){
     struct node *newNode=(struct node*)malloc(sizeof(struct node));
     if(!newNode){
        printf("Memory allocation failed\n");
     }

     newNode->info=info;
     newNode->link=NULL;
     return newNode;
}

void insertAtEnd(struct node * *headref,int info){
     struct node* newNode=(struct node*)malloc(sizeof(struct node));
     newNode->info=info;
     newNode->link=NULL;

     if(*headref==NULL){
        *headref=newNode;
     }
     else{
        struct node *temp=*headref;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=newNode;
     }
}

void display(struct node *head){
    struct node *temp=head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
}

void sortLinkedList(struct node *head){
    if(head==NULL || head->link==NULL){
        return;
    }
    int swapped;
    struct node* save;  
    struct node* rptr = NULL;

    do {
        swapped = 0;
        save = head;

        while (save->link != rptr) {
            if (save->info > save->link->info) {
                //Swap the data
                int temp = save->info;
                save->info = save->link->info;
                save->link->info = temp;
                swapped = 1;
            }
            save = save->link;
        }
        rptr = save;
    }while(swapped);
}

int main(){
    struct node *head=NULL;
    int n,value;

    printf("Enter no. of elements:");
    scanf("%d",&n);

    printf("Enter values:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        insertAtEnd(&head,value);
    }

    printf("\nOriginal Linked List:\n");
    display(head);

    sortLinkedList(head);

    printf("\nSorted Linked List:\n");
    display(head);

    return 0;
}
