#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int i;
    int n = 5;
    int vder;
    int vizq;
    int der;
    int izq;
    int raiz = getpid();
    printf("pid:%d\n",getpid());
    for (i = 0; i < n; i++) {
        if (fork()) {
            if (fork()) {
                wait(&izq);
                wait(&der);
                vizq=WEXITSTATUS(izq);
                vder=WEXITSTATUS(der);
                if(raiz==getpid()){
                    printf("Total: %d\n",vizq + vder + 1);
                    exit(vizq + vder + 1);
                }

            }
        }
    }
    sleep(60);
    exit(1);
}