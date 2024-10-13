#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define NUM_TALLOS 1   // Cambia según el número de tallos
#define NUM_FLORES 2   // Cambia según el número de flores por tallo
#define NUM_PETALOS 3  // Cambia según el número de pétalos por flor

int main() {
    pid_t pid_tallo, pid_flower, pid_petalo;
    int i, j, k, status;

    printf("%d\n",getpid());
    // Crear tallos
    for (i = 0; i < NUM_TALLOS; i++) {
        pid_tallo = fork();

        if (pid_tallo == 0) {
            // Dentro del proceso del tallo

            // Crear flores
            for (j = 0; j < NUM_FLORES; j++) {
                pid_flower = fork();

                if (pid_flower == 0) {
                    // Dentro del proceso de la flor

                    // Crear pétalos
                    for (k = 0; k < NUM_PETALOS; k++) {
                        pid_petalo = fork();

                        if (pid_petalo == 0) {
                            // Dentro del proceso de un pétalo
                            printf("Soy un pétalo (PID: %d, PPID: %d)\n", getpid(), getppid());
                            exit(0);  // Finaliza el proceso del pétalo
                        }
                        wait(&status);  // Esperar que cada pétalo termine
                    }

                    printf("Soy una flor (PID: %d, PPID: %d)\n", getpid(), getppid());
                    exit(0);  // Finaliza el proceso de la flor
                }
                wait(&status);  // Esperar que cada flor termine
            }

            printf("Soy un tallo (PID: %d)\n", getpid());
            exit(0);  // Finaliza el proceso del tallo
        }
        wait(&status);  // Esperar que cada tallo termine
    }
    sleep(30);
    printf("Árbol de procesos completo.\n");
    return 0;
}
