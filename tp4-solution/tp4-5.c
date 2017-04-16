#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

//Exercise 5.
int main(void){
  pid_t pid;
  int i, n, status;

  if (signal(SIGCHLD, SIG_IGN) == SIG_ERR){ //Silently reap children.
    perror("Couldn't install handler for SIGCHLD");
    exit(1);
  };

  for (i = 1; i <= 10; i++){
    pid = fork();
    if (pid == 0){
      printf("CHILD no. %d (PID=%d) working...\n", i, getpid());
      sleep(15); //Child working...
      printf("CHILD no. %d (PID=%d) exiting...\n", i, getpid());
      exit(0);
    }
  }
  for (i = 1; i <= 4; i++) {
    printf("PARENT: working hard (task no. %d)...\n", i);
    n = 4; while((n = sleep(n)) != 0);
    printf("PARENT: end of task no. %d\n", i);
    printf("PARENT: waiting for child no. %d...\n", i);

    //No zombies. All children are silently reaped and won't turn into zombies.

    if (pid == 0) printf("Still waiting for child to terminate.\n");
    else if (pid != -1)
      printf("PARENT: child with PID=%d terminated with exit code %d\n", pid, WEXITSTATUS(status));
  }
  exit(0);
}
