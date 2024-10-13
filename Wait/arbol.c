#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int height, width;

    if (argc != 3) {
        printf("Uso: %s <altura> <ancho>\n", argv[0]);
        exit(1);
    }

    height = atoi(argv[1]);
    width = atoi(argv[2]);

    for (int i = 0; i < height; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("Error en la creación del proceso");
            exit(1);
        } else if (pid == 0) {
            printf("Soy el proceso %d y mi padre es %d\n", getpid(), getppid());
            exit(0); // El hijo no crea más procesos
        }
    }

    // Esperar a que todos los hijos terminen
    for (int i = 0; i < height; i++) {
        wait(NULL);
    }
    sleep(30);
    return 0;
}
