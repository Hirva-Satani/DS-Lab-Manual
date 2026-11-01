#include<stdio.h>
#include<stdlib.h>

void main(){
    int n;
    printf("Enter size of array:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    int *ptr=(int *)malloc(n*sizeof(int));//n indicates size of array, and sizeof(int) shows one integer memory size
    ptr=arr; //now for arr-->*ptr and arr[i]-->*ptr+i
    
    int temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(*(ptr+i)>*(ptr+j)){
                temp=*(ptr+i);
                *(ptr+i)=*(ptr+j);
                *(ptr+j)=temp;
            }
        }        
        }
        printf("Sorted Array:");
        for(int i=0;i<n;i++){
            printf("%d ",*(ptr+i));
    }
}