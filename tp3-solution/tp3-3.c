#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAX 50000

//Exercise 3.
int main(void){
  int i;
  pid_t pid;
  char str[10];

  pid = fork();
  switch (pid){
    case -1:
      perror("fork");
      break;
    case 0: //Child process.
      for (i = 1; i <= MAX; i++){
        sprintf(str, "-%d", i);
        write(STDOUT_FILENO, str, strlen(str));
      }
      break;
    default: //Parent process.
      for (i = 1; i <= MAX; i++){
        sprintf(str, "+%d", i);
        write(STDOUT_FILENO, str, strlen(str));
      }
  }
  return 0;
}

/* Parent process ran for about 120 iterations without interferance.
 * After that, the parent and child processes run alternately.
 */
