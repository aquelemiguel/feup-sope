#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>

//Exercise 9.
int main(int argc, char *argv[], char *envp[]){

  if (argc != 2){
    printf("usage: %s dirname\n", argv[0]);
    exit(1);
  }
  pid_t pid = fork();
  int status;

  if (pid > 0){
    printf("My child is going to execute command\"ls -laR %s\"\n", argv[1]);
    waitpid(pid, status, WUNTRACED); //Only advances after child completion.
    printf("Child's return code: %i\n", WEXITSTATUS(status));

    if (WIFEXITED(status)) printf("Process ended normally.\n");
    if (WIFSIGNALED(status)) printf("Process ended abnormally.\n");

    exit(0);
  }
  else if (pid == 0){
    char *lsPath = "/bin/ls", *local[4]; //Obtained by running 'which ls' on shell.

    local[0] = "ls"; local[1] = "-laR"; local[2] = argv[1]; local[3] = NULL;

    //execlp("ls", "ls", "-laR", argv[1], NULL);
    //execl(lsPath, "ls", "-laR", argv[1], NULL);
    //execvp("ls", local);
    //execv(lsPath, local);
    execve(lsPath, local, envp);

    printf("Command not executed!\n");
    exit(1);
  }
  exit(0);
}
