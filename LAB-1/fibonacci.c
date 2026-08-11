#include <stdio.h>

void main() {
     int i, n;
     int n1 = 0, n2 = 1;
     int nextterm = n1 + n2;

     printf("Enter no. of terms: ");
     scanf("%d", &n);

 
     if (n <= 0) {
         printf("Please enter a positive integer.");
     } 

     else if (n == 1) {
         printf("Fibonacci Series: %d", n1);
     } 
     
     else if (n == 2) {
         printf("Fibonacci Series: %d,%d", n1, n2);
     } 
     else {
         printf("Fibonacci Series: %d,%d,", n1, n2);
         for (i = 3; i <= n; i++) {
            printf("%d", nextterm);
            if (i < n) printf(",");
            
            n1 = n2;
            n2 = nextterm;
            nextterm = n1 + n2;
         }
     }
}
