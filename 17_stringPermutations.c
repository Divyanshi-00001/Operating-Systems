// WAP to read string from the user within child process and print all permutations of characters of the given string.

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutations(char str[], int left, int right) {
    if (left == right) {
        printf("%s\n", str);
        return;
    }

    for (int i = left; i <= right; i++) {
        swap(&str[left], &str[i]);

        permutations(str, left + 1, right);

        swap(&str[left], &str[i]);
    }
}

int main() {
    char str[100];

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        // Child
        printf("Enter a string: ");
        scanf("%99s", str);

        int n = strlen(str);

        printf("Permutations:\n");
        permutations(str, 0, n - 1);
    }
    else {
        wait(NULL);
        printf("Parent: Child completed.\n");
    }

    return 0;
}