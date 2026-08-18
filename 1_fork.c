// Create one child and print PID and PPID of both parent and child.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        // Child
        printf("Child Process\n");
        printf("PID  = %d\n", getpid());
        printf("PPID = %d\n", getppid());
    } else {
        // Parent
        printf("Parent Process\n");
        printf("PID  = %d\n", getpid());
        printf("PPID = %d\n", getppid());

        wait(NULL);
    }

    return 0;
}