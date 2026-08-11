#include <stdio.h>

void main() {
    int num, digit;
    int freq[10] = {0};

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num > 0) {
        digit = num % 10;
        freq[digit]++;
        num = num / 10;
    }

    printf("Frequency of each digit:\n");

    for (int i = 0; i <= 9; i++) {
        if (freq[i] != 0)
            printf("%d = %d\n", i, freq[i]);
    }
}