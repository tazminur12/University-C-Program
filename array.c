#include<stdio.h>

int main()

{

int i, fib[100], n;

scanf("%d", &n);

fib[0] = 0; //initialized first element to 0

fib[1] = 1; //initialized second element to 1

for (i = 2; i < n; i++) //loop to generate ten elements

{

fib[i] = fib[i - 1] + fib[i - 2];

}

printf("The Fibonacci series is as follows ");

for (i = 0; i < n; i++)

printf("%d ", fib[i]);

}