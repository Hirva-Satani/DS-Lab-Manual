// Write a program to simulate music player application using suitable data structure. There is no estimation 
// about number of music files to be managed by the music player. Your program should support all the basic music player
// operations to play and manage the playlist

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char song[50];
    struct node *prev,*next;
};

struct node *head=NULL,*tail=NULL,*current=NULL;

void addSong(){
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    printf("Enter song name:");
    scanf("%s",newnode->song);

    newnode->next=NULL;
    newnode->prev=tail;

    if(head==NULL){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
}

void display(){
    struct node *temp=head;

    printf("\nPlaylist:\n");

    while(temp!=NULL){
        printf("%s\n",temp->song);
        temp=temp->next;
    }
}

void playFirst(){
    current=head;

    if(current!=NULL)
        printf("Playing: %s\n",current->song);
}

void playNext(){
    if(current!=NULL && current->next!=NULL){
        current=current->next;
        printf("Playing: %s\n",current->song);
    }
    else{
        printf("No next song\n");
    }
}

void playPrev(){
    if(current!=NULL && current->prev!=NULL){
        current=current->prev;
        printf("Playing: %s\n",current->song);
    }
    else{
        printf("No previous song\n");
    }
}

int main(){
    int ch;

    while(1){

        printf("\n1.Add Song");
        printf("\n2.Display Playlist");
        printf("\n3.Play First Song");
        printf("\n4.Next Song");
        printf("\n5.Previous Song");
        printf("\n6.Exit");
        printf("\nEnter choice:");
        scanf("%d",&ch);

        switch(ch){

            case 1:
                addSong();
                break;

            case 2:
                display();
                break;

            case 3:
                playFirst();
                break;

            case 4:
                playNext();
                break;

            case 5:
                playPrev();
                break;

            default:
                return 0;
        }
    }
}