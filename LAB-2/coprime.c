#include <stdio.h>

int isCoPrime(int a, int b)
{
    int i, gcd=1;

    for(i=1;i<=a && i<=b;i++)
    {
        if(a%i==0 && b%i==0)
            gcd = i;
    }

    if(gcd==1)
        return 1;
    else
        return 0;
}

int main()
{
    int arr[10];
    int i, j;

    printf("Enter 10 numbers:\n");

    for(i=0;i<10;i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nCo-Prime Pairs:\n");

    for(i=0;i<9;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(isCoPrime(arr[i], arr[j]))
                printf("%d and %d are Co-Prime\n", arr[i], arr[j]);
            else
                printf("%d and %d are NOT Co-Prime\n", arr[i], arr[j]);
        }
    }

    return 0;
}