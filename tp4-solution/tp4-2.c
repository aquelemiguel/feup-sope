#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

//Exercise 2.
void sigint_handler(int signo){
  printf("Entering SIGINT handler...\n");
  sleep(5);
  printf("Exiting SIGINT handler...\n");
}

void sigterm_handler(int signo){
  printf("Entering SIGTERM handler...\n");
  sleep(5);
  printf("Exiting SIGTERM handler...\n");
}

int main(void){

  struct sigaction action;
  action.sa_handler = sigint_handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;

  if (sigaction(SIGINT, &action, NULL) < 0){
    fprintf(stderr, "Unable to install SIGINT handler.\n");
    exit(1);
  }

  action.sa_handler = sigterm_handler; //I'm unsure whether this works. For some reason it isn't calling the handler on my terminal.

  if (sigaction(SIGTERM, &action, NULL) < 0){
    fprintf(stderr, "Unable to install SIGTERM handler\n");
    exit(1);
  }

  printf("Try me with CTRL-C...\n"); //CTRL-C isn't processed while sleeping.
  while(1) pause();

  exit(0);
}
