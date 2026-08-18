// Use return value of fork() to print Parent only in parent and Child only in child.

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid > 0) {
        printf("Parent Process\n");
    }
    else {
        printf("Child Process\n");
    }

    return 0;
}