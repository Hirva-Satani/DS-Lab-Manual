// #include<stdio.h>
// #define N 3

// int Q[N];
// int F = -1;
// int R = -1;

// void enqueue(int y){
//     if(R == N-1){
//         printf("Queue Overflow.");
//         return;
//     }
//     R++;
//     Q[R] = y;
//     if(F == -1)
//         F = 0;
// }

// int dequeue(){
//     if(F==-1){
//         printf("Queue Underflow.");
//         return -1;
//     }
//     else{
//         int y = Q[F];
//         if(F==R){
//             F = R = -1;
//             return y;
//         }
//         else{
//             F++;
//             return y;
//         }
//     }
// }

// void display(){
//     if(F==-1){
//         printf("Queue Underflow.");
//         return;
//     }
//     for(int i=F; i<=R; i++){
//         printf("%d\t",Q[i]);
//     }
// }

// void main(){
//     enqueue(10);
//     enqueue(20);
//     enqueue(30);
//     enqueue(40);
//     printf("\nDeleted element is : %d", dequeue());
//     printf("\nUpdated Queue : ");
//     display();
// }















#include<stdio.h>

#define N 3

int Q[N];
int F=-1;
int R=-1;

void enqueue(int y)
{
    if(R==N-1)
    {
        printf("Queue Overflow.\n");
        return;
    }

    R++;
    Q[R]=y;

    if(F==-1)
        F=0;
}

int dequeue()
{
    if(F==-1)
    {
        printf("Queue Underflow.\n");
        return -1;
    }

    int y=Q[F];

    if(F==R)
    {
        F=R=-1;
    }
    else
    {
        F++;
    }

    return y;
}

void display()
{
    if(F==-1)
    {
        printf("Queue Underflow.\n");
        return;
    }

    printf("Queue: ");

    for(int i=F;i<=R;i++)
    {
        printf("%d\t", Q[i]);
    }

    printf("\n");
}

int main()
{
    while(1)
    {
        int choice;

        printf("\n--- QUEUE MENU ---\n");
        printf("Enter 1 to enqueue an element\n");
        printf("Enter 2 to dequeue an element\n");
        printf("Enter 3 to display the queue\n");
        printf("Enter 4 to exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int x;

                printf("Enter an element to be inserted: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            }

            case 2:
            {
                int deletedElement = dequeue();

                if(deletedElement != -1)
                    printf("Deleted Element: %d\n", deletedElement);
                break;
            }

            case 3:
            {
                display();
                break;
            }

            case 4:
            {
                printf("Exiting...\n");
                return 0;
            }

            default:
            {
                printf("Invalid choice.\n");
            }
        }
    }
}