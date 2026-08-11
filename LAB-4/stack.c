#include <stdio.h>

int stack[10];
int top=-1;//initially empty

void push(int x){
    if(top>=9){
        printf("Stack Overflow");
        return;
    }
    else{
        top++;
        stack[top]=x;
    }
}

int pop(){
    if(top<0){
        printf("Stack Underflow");
        return 0;
    }
    top--;
    return(stack[top+1]);
}

int peep(int i){
    if(top-i+1<=-1){
        printf("Stack Underflow");
        return 0;
    }
    return stack[top-i+1];
}

//it will not start from 0 but with 1
void change(int i,int x){    
    if(top-i+1<=-1){
        printf("Stack Underflow");
        return;
    }
    stack[top-i+1]=x;
    return;
}

void display(){
    if(top<0){
        printf("Stack Underflow");
        return;
    }
    printf("[");
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("] \n");
}

int main(){
    while(1){
        int choice;
        printf("Enter 1 to push an element\n enter 2 to pop out an element\n Enter 3 to display the stack\n Enter 4 to peep an element\n Enter 5 to change an element\n Enter your choice");
        scanf("%d",&choice);

        switch(choice){
            case 1:{
                int x;
                printf("\nEnter an element to be pushed:");
                scanf("%d",&x);
                push(x);
                break;
            }
            case 2:{
                int poppedelement=pop();
                printf("Popped Element:%d",poppedelement);
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                int i;
                printf("Enter the address of the element to be peeped:");
                scanf("%d",&i);
                int peepedelement=peep(i);
                printf("The element on %d position is %d",i,peepedelement);
                break;
            }
            case 5:{
                int i,x;
                printf("Enter the position on which the number is to be changed:");
                scanf("%d",&i);
                printf("Enter the new number:");
                scanf("%d",&x);
                change(i,x);
                break;
            }
            default:{
                return 0;
            }
        }
    }
}


