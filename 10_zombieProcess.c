// Demonstrate a zombie process and observe using ps. A zombie is a terminated child whose parent has not yet called wait().

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
        printf("Child terminating...\n");
        exit(0);
    }
    else {
        printf("Parent PID = %d\n", getpid());
        printf("Child PID  = %d\n", pid);

        printf("Parent sleeping. Check process status now.\n");

        sleep(20);

        printf("Parent terminating.\n");
    }

    return 0;
}