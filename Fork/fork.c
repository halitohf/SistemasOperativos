#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
     int mipid = 0;
     pid_t pid;
     int n;

     printf("Ingresa un valor de n\n");
     scanf("%d", &n);
     printf("Raiz: %d\n", getpid());

     for (int i = 0; i < n; i++){
          pid = fork();
          if (pid == 0)
             break;
     }
     sleep(1000);
     exit(0);
}