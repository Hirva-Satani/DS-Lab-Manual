//GCD between two nodes
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

struct Node *head = NULL;

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
    while (temp->link != NULL)
        temp = temp->link;
    temp->link = newNode;
}

void display() {
    struct Node* temp=head;
    while (temp!=NULL) {
        printf("%d -> ",temp->info);
        temp=temp->link;
    }
}

//calculate GCD of two numbers
int findGCD(int a, int b){
    if (b==0)
        return a;
    return findGCD(b,a%b);
}

void insertGCDNodes() {
    struct Node* current = head;
    while (current!=NULL && current->link!=NULL) {
        int gcd=findGCD(current->info,current->link->info);
        struct Node* gcdNode = createNode(gcd);

        // Insert gcdNode between current and current->link
        gcdNode->link = current->link;
        current->link = gcdNode;
        current = gcdNode->link;
    }
}

int main() {
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i=0;i<n;i++) {
        scanf("%d",&value);
        insertEnd(value);
    }

    printf("\nOriginal Linked List:\n");
    display();

    insertGCDNodes();

    printf("\nLinked List After Inserting GCD Nodes:\n");
    display();

    return 0;
}