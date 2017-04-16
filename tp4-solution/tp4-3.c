#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

//Exercise 3.
static int ascending = 0; //Spooky global variables.

void sigusr_handler(int signo){
  if (signo == SIGUSR1) ascending = 0;
  if (signo == SIGUSR2) ascending = 1;
}

int main(void){

  int num = 0, count = 0;
  srand(time(NULL));

  if (signal(SIGUSR1, sigusr_handler) == SIG_ERR){
    fprintf(stderr, "Unable to install SIGUSR1 handler\n");
    exit(1);
  }
  if (signal(SIGUSR2, sigusr_handler) == SIG_ERR){
    fprintf(stderr, "Unable to install SIGUSR2 handler\n");
    exit(1);
  }

  pid_t pid = fork();
  while (count < 50){
    if (pid == -1) perror("Fork error.");
    if (pid > 0){ //Parent process.
      int r = rand() % 2; //Generates either 0 or 1.

      if (r == 0) kill(pid, SIGUSR1);
      else kill(pid, SIGUSR2);
      sleep(1); //There might be some syncing issues, but good enough.
    }
    if (pid == 0){ //Child process.
      if (ascending) printf("%i\n", num++);
      else printf("%i\n", num--);

      count++;
      sleep(1);
    }
  }


  return 0;
}
