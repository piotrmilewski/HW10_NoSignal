/*Piotr Milewski
  Systems pd10
  HW10 -- Fire up the batSIGNAL
  2017-11-08*/

#include "main.h"

void printError(int err){
  if (err == -1){
    printf("errno: %d, %s\n", err, strerror(errno));
    exit(1);
  }
}

static void sighandler( int signo){
  int fd;
  if (signo == SIGINT){
    fd = open("Signals.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    printError(fd);
  
    char str[64] = "Exit due to signal: SIGINT\n";
    printError( write(fd, str, strlen(str)));
    printError( close(fd));
    
    printf("\nInterrupt from keyboard\n\n");
    exit(1);
  }
  else if (signo == SIGUSR1)
    printf("\nParent Process PID: %d\n\n", getppid());
}

int main(){

  umask(0000);

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while (1) {
    printf("Current Process PID: %d\n", getpid());
    sleep(1);
  }

  return 0;
}
