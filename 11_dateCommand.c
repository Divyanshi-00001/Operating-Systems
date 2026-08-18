// Use fork(), exec(), and wait() to execute date command.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        // Child executes date
        printf("Child executing date command:\n");

        execl("/bin/date", "date", (char *)NULL);

        // Only executes if execl fails
        perror("execl failed");
        exit(1);
    }
    else {
        // Parent waits for child
        wait(NULL);

        printf("Parent: Child has completed.\n");
    }

    return 0;
}