// Demonstrate an orphan process. An orphan process occurs when the parent terminates before the child

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        // Child
        printf("Child before parent terminates:\n");
        printf("PID  = %d\n", getpid());
        printf("PPID = %d\n", getppid());

        sleep(5);

        printf("\nChild after parent terminates:\n");
        printf("PID  = %d\n", getpid());
        printf("PPID = %d\n", getppid());
    }
    else {
        // Parent terminates immediately
        printf("Parent PID = %d\n", getpid());
        printf("Parent terminating...\n");
        exit(0);
    }

    return 0;
}