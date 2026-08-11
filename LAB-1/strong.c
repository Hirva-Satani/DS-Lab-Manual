#include <stdio.h>

void main() {
    int num, temp, digit, fact, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (temp > 0) {
        digit = temp % 10;
        fact = 1;

        
        for (int i = 1; i <= digit; i++) {
            fact = fact * i;
        }

        sum = sum + fact;
        temp = temp / 10;
    }

    if (sum == num)
        printf("%d is a Strong Number.", num);
    else
        printf("%d is not a Strong Number.", num);
}