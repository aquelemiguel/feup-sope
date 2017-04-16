#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

//Exercise 6.
void sigalarm_handler(int signo){
  printf("Natural outcome.\n");
  if (raise(SIGKILL) != 0) perror("Couldn't kill self: ");
}

int main(int argc, char* argv[]){
  signal(SIGALRM, sigalarm_handler); //Installs alarm signal handler.

  int limit = atoi(argv[0]); //Limit imposed by the first function.
  char* message = argv[1];

  alarm(30); //If 30 seconds elapse, the handler is called.

  for (int i = 0; i < limit; i++){
    if (i % 5 == 0) printf("%s\n", message); //Every five seconds, output message.
    sleep(1);
  }
  printf("%i seconds exceeded!\n", limit);
  exit(0);
}
