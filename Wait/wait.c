#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    if (fork()) {
        int valor;
        printf("Padre, esperando\n");
        wait(&valor);
        printf("Hijo termina %d\n", WEXITSTATUS(valor));
    }
    else {
        sleep(5);
        exit(9);
    }
    return 0;
}