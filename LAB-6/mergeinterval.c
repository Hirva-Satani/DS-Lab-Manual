#include<stdio.h>

struct Interval{
    int start,end;
};

void main(){
    int n;

    printf("Enter number of intervals:");
    scanf("%d",&n);

    struct Interval a[n],stack[n];
    int top=-1;

    printf("Enter intervals:\n");
    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i].start,&a[i].end);

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i].start>a[j].start){

                struct Interval temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    stack[++top]=a[0];

    for(int i=1;i<n;i++){

        struct Interval curr=stack[top];

        if(a[i].start<=curr.end){

            if(a[i].end>curr.end)
                stack[top].end=a[i].end;
        }
        else{
            stack[++top]=a[i];
        }
    }

    printf("Merged Intervals:\n");

    for(int i=0;i<=top;i++){
        printf("[%d,%d] ",stack[i].start,stack[i].end);
    }
}