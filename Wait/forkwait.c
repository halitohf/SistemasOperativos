#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

    int n;
    printf("Ingresa n:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        if (!fork()){
            sleep(1);
            exit(i);
        }
    for (i = 0; i < n; i++){
            wait(&i);
            printf("El Hijo %d termino con valor %d\n", i, WEXITSTATUS(i));
        }
        return 0;
    }
}