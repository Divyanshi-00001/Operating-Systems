// WACP to open file in child process write all the even nos upto n and then pass the name of file through pipe to parent process and the read and print the content of file.
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
    else if(p>0) {
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
       int n;
       scanf("%d",&n);
       for(int i=0;i<=n;i+=2) {
        fprintf(f,"%d\n",i);
       }
       fclose(f);
       char ch[] = "input.txt";
       write(fd[1],ch,strlen(ch)+1);
       close(fd[1]);
       exit(0);
    }
    return(0);
}