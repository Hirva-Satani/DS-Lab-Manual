#include <stdio.h>
#include <string.h>

void main()
{
    char name[50][50], temp[50];
    int n, i, j;

    printf("Enter the number of names: ");
    scanf("%d", &n);

    printf("Enter %d names:\n", n);

    for(i=0;i<n;i++)
    {
        scanf("%s", name[i]);
    }

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(name[i], name[j]) > 0)
            {
                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
            }
        }
    }

    printf("\nNames in alphabetical order:\n");

    for(i=0;i<n;i++)
    {
        printf("%s\n", name[i]);
    }
}