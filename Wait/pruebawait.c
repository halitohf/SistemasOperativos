#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int nivel = 0;
    int max_nivel = 5;  

    printf("Proceso raíz: PID=%d\n", getpid());

    while (nivel < max_nivel) {
        pid_t pid = fork();  // Crear un proceso hijo

        if (pid < 0) {
            // Error al crear el proceso
            error("Error al crear el fork");
            exit(1);
        }

        if (pid > 0) {
            // Proceso padre: se mata (sale) después de crear al hijo
            printf("Padre (PID=%d, nivel=%d) crea a su hijo (PID=%d)\n", getpid(), nivel, pid);
            exit(0);  // Termina el padre
        } else {
            // Proceso hijo: continúa la creación de más hijos
            printf("Hijo (PID=%d, nivel=%d)\n", getpid(), nivel + 1);
            nivel++;  // Incrementa el nivel de profundidad
            sleep(1);  // Espera un poco antes de crear el siguiente hijo
        }
    }

    // Solo los hijos en el último nivel llegarán aquí
    printf("Proceso en el nivel final (PID=%d)\n", getpid());
    return 0;
}
