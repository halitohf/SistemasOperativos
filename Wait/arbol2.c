#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int i;
    int n = 5; // Número de niveles de clonación
    int status;
    int total_procesos = 0; // Contador de procesos

    printf("Proceso raíz, PID: %d\n", getpid());

    for (i = 0; i < n; i++) {
        pid_t pid = fork(); // Crear un nuevo proceso hijo

        if (pid < 0) {
            // Error en fork
            perror("Error en fork");
            exit(1);
        }

        if (pid == 0) {
            // Estamos en el proceso hijo
            continue; // El hijo continúa al siguiente ciclo
        } else {
            // Estamos en el proceso padre
            total_procesos++; // Contamos el hijo creado
            wait(&status); // Esperamos a que el hijo termine
            if (WIFEXITED(status)) {
                total_procesos += WEXITSTATUS(status); // Sumamos los procesos que retornó el hijo
            }
            break; // El padre termina después de crear un hijo
        }
    }

    if (getpid() == getppid()) {
        // Solo el proceso raíz imprime el total
        printf("Total de procesos creados: %d\n", total_procesos + 1); // +1 por el proceso raíz
    }

    exit(total_procesos + 1); // Sumar 1 para incluir el proceso actual
}
