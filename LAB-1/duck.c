#include <stdio.h>

void main() {
    int num, temp, digit, isDuck = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (temp > 0) {
        digit = temp % 10;

        if (digit == 0) {
            isDuck = 1;
            break;
        }

        temp = temp / 10;
    }

    if (isDuck)
        printf("%d is a Duck Number.", num);
    else
        printf("%d is not a Duck Number.", num);

}