#include<stdio.h>
#include<stdlib.h>

void main(){
    int n,sum=0;
    printf("Enter size of array:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    int *ptr=(int *)malloc(n*sizeof(int));//n indicates size of array, and sizeof(int) shows one integer memory size
    ptr=arr;//if & written then only one variable memory address stored

    for(int i=0;i<n;i++){
        sum=sum+*(ptr+i);
    }

    printf("Sum of given n numbers:%d %d",sum,ptr+n);
    free(ptr);
}