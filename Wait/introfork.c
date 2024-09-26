#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int i = 0;
    int i2 = 0;
    for (i = 0; i < 5; i++) {
        if (fork()) {
            printf("Padre: %d\n");
            wait(&i2);
            i += WEXITSTATUS(i2);
            exit(i2+1);
        }else{
            exit(i2+1);
            printf("Hijo:%d\n",i2);
        }
    }
}