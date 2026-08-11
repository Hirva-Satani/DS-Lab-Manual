#include <stdio.h>
void main()
{
    int num, temp, first, last, divisor = 1, middle, result;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (temp >= 10)
    {
        temp = temp / 10;
        divisor = divisor * 10;
    }

    first = num / divisor;
    last = num % 10;
    middle = (num % divisor) / 10;

    result = last * divisor + middle * 10 + first;

    printf("Number after swapping first and last digit = %d", result);
}