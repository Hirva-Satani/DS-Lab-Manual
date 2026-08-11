#include <stdio.h>

int main() {
    int num, temp, digit;
    int count = 0, sum = 0, product = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (temp > 0) {
        digit = temp % 10;
        count++;
        sum = sum + digit;
        product = product * digit;
        temp = temp / 10;
    }

    printf("Number of digits = %d\n", count);
    printf("Sum of digits = %d\n", sum);
    printf("Product of digits = %d\n", product);

    return 0;
}