// Fibonacci function in child + factorial in parent + Armstrong numbers

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void fibonacci(int n) {
    int a = 0, b = 1, c;

    printf("Fibonacci Series: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", a);

        c = a + b;
        a = b;
        b = c;
    }

    printf("\n");
}

unsigned long long factorial(int n) {
    unsigned long long fact = 1;

    for (int i = 1; i <= n; i++)
        fact *= i;

    return fact;
}

int isArmstrong(int n) {
    int original = n;
    int sum = 0;
    int digits = 0;
    int temp = n;

    if (n == 0)
        return 1;

    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = n;

    while (temp != 0) {
        int digit = temp % 10;
        int power = 1;

        for (int i = 0; i < digits; i++)
            power *= digit;

        sum += power;
        temp /= 10;
    }

    return sum == original;
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        // Child
        printf("\nChild Process\n");
        fibonacci(n);
    }
    else {
        // Parent
        printf("\nParent Process\n");

        printf("Factorial of %d = %llu\n", n, factorial(n));

        printf("Armstrong numbers up to %d: ", n);

        for (int i = 0; i <= n; i++) {
            if (isArmstrong(i))
                printf("%d ", i);
        }

        printf("\n");

        wait(NULL);
    }

    return 0;
}