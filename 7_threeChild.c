// Create three child processes. Each child should print its PID, PPID, and child number

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 1; i <= 3; i++) {

        pid_t pid = fork();

        if (pid < 0) {
            printf("Fork failed\n");
            return 1;
        }

        if (pid == 0) {
            printf("Child %d\n", i);
            printf("PID  = %d\n", getpid());
            printf("PPID = %d\n\n", getppid());

            return 0;
        }
    }

    // Parent waits for all three children
    for (int i = 1; i <= 3; i++) {
        wait(NULL);
    }

    printf("Parent finished.\n");

    return 0;
}