1 1 1 1 1 #include <stdio.h>
2 2 2 2 2 
3 3 3 3 3 
4 4 4 4 4 
5 5 5 5 5 
6 6 6 6 6 
7 7 7 7 7 
8 8 8 8 8 int factorial(int n) {
9 9 9 9 9         return 1;
10 10 10 10 10     return n * factorial(n - 1);
11 11 11 11 11 }
12 12 12 12 12 
13 13 13 13 13 int main() {
14 14 14 14 14     int num;
15 15 15 15 15 
16 16 16 16 16     printf("Enter a number to calculate its factorial: ");
17 17 17 17 17     scanf("%d", &num);
18 18 18 18 18 
19 19 19 19 19     if (num < 0) {
20 20 20 20 20         printf("Factorial is not defined for negative numbers.\n");
21 21 21 21 21     } else {
22 22 22 22 22         printf("Factorial of %d is %d\n", num, factorial(num));
23 23 23 23 23     }
24 24 24 24 24 
25 25 25 25 25     return 0;
26 26 26 26 26 
27 27 27 27 27 
28 28 28 28 28     
29 29 29 29 29      
30 30 30 30 30 }