#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int i;
    int n = 5;
    printf("pid:%d\n",getpid());
    for (i = 0; i < n; i++) {
        if (fork()) {
            if (fork()) {
                sleep(1000);
                exit(0);
            }
        }
    }
    sleep(1000);
}