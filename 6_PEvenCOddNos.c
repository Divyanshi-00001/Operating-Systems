// Parent prints even numbers and child prints odd numbers from 1 to 20.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        // Child prints odd numbers
        printf("Child - Odd numbers:\n");

        for (int i = 1; i <= 20; i += 2) {
            printf("%d ", i);
        }

        printf("\n");
    }
    else {
        // Parent prints even numbers
        printf("Parent - Even numbers:\n");

        for (int i = 2; i <= 20; i += 2) {
            printf("%d ", i);
        }

        printf("\n");

        wait(NULL);
    }

    return 0;
}