// Write a C program where number is prime or not in child; parent process calculates factorial. Print PID & PPID.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int isPrime(int n) {
    if (n < 2)
        return 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
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
        printf("PID = %d\n", getpid());
        printf("PPID = %d\n", getppid());

        if (isPrime(n))
            printf("%d is Prime\n", n);
        else
            printf("%d is Not Prime\n", n);
    }
    else {
        // Parent
        unsigned long long fact = 1;

        for (int i = 1; i <= n; i++) {
            fact *= i;
        }

        printf("\nParent Process\n");
        printf("PID = %d\n", getpid());
        printf("PPID = %d\n", getppid());
        printf("Factorial of %d = %llu\n", n, fact);

        wait(NULL);
    }

    return 0;
}