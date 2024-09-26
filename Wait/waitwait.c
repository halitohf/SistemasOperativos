#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int c;
    printf("Ingresa el numero de repeticiones:\n");
    scanf("%d\n",&c);
    
    for(int i=0;i<c;i++){
        if(!fork()){
            exit(i);
        }else {
            fork();
            printf("Soy el proceso padre%d\n",i);
        }
    }
    return 0;
}