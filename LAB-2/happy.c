#include <stdio.h>
void main()
{
    int num, temp, digit, sum;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num!=1 && num!=4)
    {
        sum=0;
        temp=num;
        while(temp>0)
        {
            digit=temp%10; 
            // 19%10==9   1%10==1
            sum=sum+(digit*digit); 
            // 0+(9*9)=81   81+(1*1) 82
            temp=temp/10; 
            // temp=1
        }
        num=sum;
    }

    if (num==1)
        printf("Happy Number");
    else
        printf("Not a Happy Number");
}