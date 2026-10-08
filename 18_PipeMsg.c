// Sending a msg through pipe from child to parent then read and print it on screen.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main() {
    pid_t p;
    int fd[2];
    if(pipe(fd)==-1) {
        printf("Pipe failed\n");
        return(0);
    }
    p=fork();
    if(p<0) {
        printf("fork failed\n");
        return(0);
    }
    else if(p==0) {
        char str[100];
        printf("Enter a string");
        scanf("%99s",str);
        close(fd[0]);
        write(fd[1],str,strlen(str)+1);
        close(fd[1]);
        exit(0);
    }
    else {
        wait(NULL);
        close(fd[1]);
        char str[100];
        read(fd[0],str,sizeof(str));
        close(fd[0]);
        printf("%s",str);
        exit(0);
    }
    return(0);
}