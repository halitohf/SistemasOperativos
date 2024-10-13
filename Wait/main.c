#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    int i, j, k, p1=7, p2=(p1+1)/2;

    printf("%d\n", getpid());
    for (i = 0, j = p1 - 1; i < (p2 - 1); i++, j = j - 2) {
        if (fork()) {
            break;
        }
    }

    for (k = j; k > 0; k--) {
        if (fork()) {
            break;
        }
    if(i==0){
        sleep(30);
        exit(1);
    }
    if(j==k){
        wait(&v1);
        wait(&v2);
        if(raiz==getpid()){
            printf("");
        }
        exit(WEXITSTATUS(v)+1 + WEXITSTATUS(v2)+1);
        wait (&v);
        exit(WEXITSTATUS(v)+1);

        printf("Total:%d\n",WEXITSTATUS(v1));

    }&
}
}


