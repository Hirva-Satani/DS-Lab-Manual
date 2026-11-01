#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node *link;
};

struct Node *head=NULL;

struct Node *createNode(int info){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(!newNode){
        printf("Memory allocation failed\n");
    }
    newNode->info=info;
    newNode->link=NULL;
    return newNode;
}

void insertEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->link != NULL) temp = temp->link;
    temp->link = newNode;
}

void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

struct Node* swapList(struct Node *head){ 
    if (head==NULL || head->link==NULL) { 
        return head; 
    } 
 
    struct Node *temp = head; 
    struct Node *t = temp->link;  
 
    temp->link = t->link; 
    t->link = temp; 
    head = t;  
 
    while (temp->link != NULL && temp->link->link != NULL) { 
        t = temp->link->link;           
        temp->link->link = t->link;     
        t->link = temp->link;           
         
        struct Node *oldTemp = temp;    
        temp = temp->link;              
        oldTemp->link = t;              
    } 
    return head; 
}

void main(){
    int n, value;

    printf("How many elements in a linked lisT? ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter value %d: ",i+1);
        scanf("%d",&value);
        insertEnd(value);
    }

    printf("Original List: \n");
    display();

    head = swapList(head);

    printf("\nSwapped List: \n");
    display();
}