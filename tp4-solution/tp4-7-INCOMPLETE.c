#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

//Exercise 7.
void sigchld_handler(int signo){
  int status;
  pid_t pid;

  pid = wait(&status);
  printf("Child with PID = %i terminated with code %i.", pid, WEXITSTATUS(status));

}

int main(int argc, char* argv[]){

  sigset_t set;
  sigemptyset(&set);
  sigaddset(&set, SIGCHLD);
  sigprocmask(SIG_UNBLOCK, &set, NULL);

  if (signal(SIGCHLD, sigchld_handler) == SIG_ERR){
    fprintf(stderr, "Unable to install SIGCHLD handler\n");
    exit(1);
  }

  int killAllChildren = 1;

  for (int i = 1; i < argc; i++){
    pid_t pid = fork();

    if (pid > 0){ //Parent process.

      //if (WEXITSTATUS(status) != 0) killAllChildren = 0;

      //if (killAllChildren) kill(pid, SIGKILL);

    }
    if (pid == 0){ //Child process will be transformed into an executable.
      printf("Executing %s at PID = %i.\n", argv[i], getpid());
      if (execl(argv[i], "", NULL) == -1) perror("Error opening file: ");
    }
    if (signal(SIGCHLD, sigchld_handler) == SIG_ERR){
      fprintf(stderr, "Unable to install SIGCHLD handler\n");
      exit(1);
    }
  }
}
