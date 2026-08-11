#include <stdio.h>

void main()
{
    int arr[100],n,i,num;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements in ascending order:\n", n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the number to insert: ");
    scanf("%d",&num);

    for(i=n-1;i>=0 && arr[i]>num;i--)
    {
        arr[i+1]=arr[i];
    }

    arr[i+1]=num;
    n++;

    printf("Array after insertion:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}