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
    ptr=arr;

    int max=*ptr;
    for(int i=0;i<n;i++){
        if(max < *(ptr+i)){
            max=*(ptr+i);
        }
    }
    printf("Largest element: %d %d",max,ptr+n);
    free(ptr);
}