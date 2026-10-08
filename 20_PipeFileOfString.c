// WACP to create input.txt in parent process and write your name, univ. roll no. and class roll no. in it and read same file in child process and print the content.

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
        close(fd[1]);
        char ch[100];
        read(fd[0],ch,sizeof(ch));
        close(fd[0]);
        FILE *f = fopen(ch,"r");
        if(f==NULL) {
            printf("file failed\n");
            exit(0);
        }
        char c;
        while((c=fgetc(f))!=EOF) {
            putchar(c);
        }
        fclose(f);
        exit(0);
    }
    else {
       close(fd[0]);
       FILE *f = fopen("input.txt","w");
       if(f==NULL) {
            printf("file failed\n");
            exit(0);
       }
       fprintf(f,"Name: Divyanshi Agarwal\n");
       fprintf(f, "Univ. Roll No.- 2025827\n");
       fprintf(f, "Class Roll No.- 22\n");
       fclose(f);
       char ch[] = "input.txt";
       write(fd[1],ch,strlen(ch)+1);
       close(fd[1]);
       exit(0);
    }
    return(0);
}