#include <stdio.h>
void main(){
    int n,i,j,k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if (arr[i]==arr[j]){
                // Shift left to delete duplicate
                for (k=j;k<n-1;k++){
                    arr[k]=arr[k + 1];
                }
                n--;   // decrease size
                j--;   // recheck the new element at this index
            }
        }
    }

    printf("Array after deleting duplicates:\n");
    for (i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
}
