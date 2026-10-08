// Question: Write a program to print the Fibonacci series up to n in the child process and factorial of n in the parent process.

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
        fibonacci(n);
    }
    else {
        // Parent
        unsigned long long fact = 1;

        for (int i = 1; i <= n; i++) {
            fact *= i;
        }

        printf("Factorial of %d = %llu\n", n, fact);

        wait(NULL);
    }

    return 0;
}