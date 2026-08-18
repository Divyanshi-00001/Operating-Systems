// Child prints 1 to 5 and parent waits using wait(). 

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
        // Child
        for (int i = 1; i <= 5; i++) {
            printf("%d\n", i);
        }
    }
    else {
        // Parent
        wait(NULL);
        printf("Parent: Child has finished.\n");
    }

    return 0;
}