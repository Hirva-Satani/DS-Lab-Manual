#include<stdio.h>
void main(){
    int arr[11],loc,ele,temp;
     
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
    printf("\nEnter an element:");
    scanf("%d",&ele);

    for(int i=0;i<11;i++){
        if(i>=loc){
            temp=arr[i];
            arr[i]=ele;
            ele=temp;
        }
    }

    printf("The new array is:");
    for(int i=0;i<11;i++){
        printf("%d ",arr[i]);
    }
}