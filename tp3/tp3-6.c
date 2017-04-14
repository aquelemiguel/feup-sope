#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>

//Exercise 6.
int main(void){
  pid_t pid;
  int i, j;

  printf("I'm process %d. My parent is %d.\n", getpid(), getppid());
  for (i = 1; i <= 3; i++){
    pid = fork();
    if (pid < 0){
      printf("fork error");
      exit(1);
    }
    else if (pid == 0){
      printf("I'm process %d. My parent is %d. I'm going to work for 1 second...\n", getpid(), getppid());
      sleep(1);
      printf("I'm process %d. My parent is %d. I finished my work\n", getpid(), getppid());
      exit(0);
    }else{
      /* If the child process hasn't finished, it'll end up being a zombie, regardless.
       * This method reduces the zombie number, but most likely always leaves one on,
       * probably due to the fact that the child process does not complete before father
       * is called.
       */
      waitpid(-1, NULL, WNOHANG);
      for (j = 1; j <= 10; j++){
        sleep(1);
        printf("Father working...\n");
      }
    }
  }
  exit(0);
}
