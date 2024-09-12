#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
     int mipid = 0;
     pid_t pid;
     mipid = getpid();
     pid = fork();
     switch (pid)
     {

     case 0:
          printf("pid: %d mipid: %d\n", pid, mipid);
          break;
     default:
          printf("pid: %d mipid: %d\n", pid, mipid);
          break;
     }
     sleep(1000);
     exit(0);
}