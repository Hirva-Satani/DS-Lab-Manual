#include<stdio.h>
void main(){
    int arr[10],loc,ele,temp;
     
    printf("Enter array elements:");
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }

    printf("Array elements are:");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }

    printf("\nEnter a location:");
    scanf("%d",&loc);

    for(int i=0;i<9;i++){
        if(i>=loc){
            temp=arr[i];
            arr[i]=arr[i+1];
        }
    }

    printf("The new array is:");
    for(int i=0;i<9;i++){
        printf("%d ",arr[i]);
    }
}