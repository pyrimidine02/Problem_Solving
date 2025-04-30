#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1 = fork();
    pid_t pid2 = fork();
    if (pid1 > 0 && pid2 > 0) {
        wait(NULL);
        printf("%d\n%d\n", pid1, pid2);
        printf("A\n");
    } else if (pid1 == 0 && pid2 > 0) {
        wait(NULL);
        printf("%d\n%d\n", pid1, pid2);
        printf("B\n");
    } else if (pid1 > 0 && pid2 == 0) {
        wait(NULL);
        printf("%d\n%d\n", pid1, pid2);
        printf("C\n");
    } else {
        wait(NULL);
        printf("%d\n%d\n", pid1, pid2);
        printf("D\n");
    }
    return 0;
}
