#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    int priority;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data, int prio){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->info = data;
    new->priority = prio;

    if(front == NULL){
        new->link = new;
        front = rear = new;
        return;
    }
    if(new->priority <= front->priority){
        new->link = front;
        rear->link = new;
        front = new;
        return;
    }
    struct node *save = front;
    while(save != rear && new->priority >= save->link->priority){
        save = save->link;
    }
    new->link = save->link;
    save->link = new;
    if(save == rear){
        rear = new;
    }
}
void dequeue(){
    if(front==NULL){
        printf("\nqueue underflow");
        return;
    }
    if(front== rear){
        printf("\n%d is dequeued",front->info);
        front=rear=NULL;
        return;
    }
    else{
        printf("\n%d is dequeued",front->info);
        front=front->link;
        rear->link=front;
        return;
    }
}
void display(){
    if(front == NULL){
        printf("Queue is empty.");
        return;
    }
    struct node *save = front;
    while(save != rear){
        printf("%d\t", save->info);
        save = save->link;
    }
    printf("%d", rear->info);
}

int main(){
    enqueue(101,5);
    enqueue(102,1);
    enqueue(103,10);
    display();
    dequeue();
    display();
    return 0;
}