#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

//Exercise 1.
void sigint_handler(int signo){
  printf("In SIGINT handler...\n");
}

int main(void){
  /*if (signal(SIGINT, sigint_handler) < 0){
    fprintf(stderr, "Unable to install SIGINT handler\n");
    exit(1);
  }*/
  
  struct sigaction sa;
  sa.sa_handler = sigint_handler; //Call to handler function.
  sigemptyset(&sa.sa_mask); //Empty blocked signals on handler execution.
  sa.sa_flags = 0; //No new dispositions.

  if (sigaction(SIGINT, &sa, NULL) == -1){
    fprintf(stderr, "Unable to install SIGINT handler\n");
    exit(1);
  }
  printf("Sleeping for 30 seconds...\n");

  for (unsigned int remaining = sleep(30); remaining > 0; remaining = sleep(remaining));

  printf("Waking up...\n");
  exit(0);
}
