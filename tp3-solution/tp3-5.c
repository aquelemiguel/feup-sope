#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

//Exercise 5.
int main(void){
  pid_t pid1 = fork(), pid2;

  if (pid1 == -1) perror("fork 1");
  if (pid1 > 0){ //Parent process.
    write(STDOUT_FILENO, "Hello ", 6);
  }
  if (pid1 == 0){
    write(STDOUT_FILENO, "my ", 3);
    pid2 = fork(); //There has to be a more elegant way to do this.
    if (pid2 == -1) perror("fork 2");
    if (pid2 > 0){ //Parent process.
      write(STDOUT_FILENO, "friends!", 8);
    }
  }
}
