// WAP to find sum of elements in an array within child process & check whether given sum is prime or not in parent process.

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

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        // Child calculates sum
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        printf("Child: Sum = %d\n", sum);
    }
    else {
        // Parent
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        wait(NULL);

        if (isPrime(sum))
            printf("Parent: Sum %d is Prime\n", sum);
        else
            printf("Parent: Sum %d is Not Prime\n", sum);
    }

    return 0;
}