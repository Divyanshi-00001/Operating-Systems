// Question. WAP in which the child process will call another child process.

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
        // First child
        printf("First Child\n");
        printf("PID = %d\n", getpid());
        printf("PPID = %d\n", getppid());

        pid_t pid2 = fork();

        if (pid2 < 0) {
            printf("Second fork failed\n");
            return 1;
        }

        if (pid2 == 0) {
            // Second child
            printf("Second Child\n");
            printf("PID = %d\n", getpid());
            printf("PPID = %d\n", getppid());
        }
        else {
            wait(NULL);
        }
    }
    else {
        // Original parent
        wait(NULL);
        printf("Parent finished.\n");
    }

    return 0;
}