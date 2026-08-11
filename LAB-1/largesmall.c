#include <stdio.h>

void main() {
    int num, digit;
    int largest = 0, smallest = 9;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num > 0) {
        digit = num % 10;

        if (digit > largest)
            largest = digit;

        if (digit < smallest)
            smallest = digit;

        num = num / 10;
    }

    printf("Largest digit = %d\n", largest);
    printf("Smallest digit = %d", smallest);
}