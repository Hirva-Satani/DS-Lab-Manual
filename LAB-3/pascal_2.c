#include <stdio.h>
void main()
{
    int n, i, j;

    printf("Enter the number of rows:");
    scanf("%d", &n);

    int num;

    for (i=0;i<n;i++)
    {
        num=1;

        for(j=0;j<=i;j++)
        {
            printf("%d ",num);
            num=num*(i-j)/(j+1);
        }

        printf("\n");
    }
}