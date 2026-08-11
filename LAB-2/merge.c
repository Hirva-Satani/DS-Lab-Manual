#include <stdio.h>
void main() {
    int n1, n2, i;

    printf("Enter size of first array: ");
    scanf("%d", &n1);
    int arr1[n1];

    printf("Enter %d elements of first array:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);
    int arr2[n2];

    printf("Enter %d elements of second array:\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    int merged[n1 + n2];
    for (i = 0; i < n1; i++) {
        merged[i] = arr1[i];
    }
    for (i = 0; i < n2; i++) {
        merged[n1 + i] = arr2[i];
    }

    printf("Merged array:\n");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
// Sorting Array Logic
    for(int i=0;i<n1+n2;i++){
        for(int j=i+1;j<n1+n2;j++){
            if(merged[i]>merged[j]){
                int temp=merged[i];
                merged[i]=merged[j];
                merged[j]=temp;
            }
        }
    }

    printf("\nMerged Sorted array:\n");
    for (i=0;i<n1+n2;i++) {
        printf("%d ", merged[i]);
    }
}
