#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

//Exercise 4.
void childThenParent(void){
  pid_t pid = fork();
  if (pid == -1) perror("fork");
  if (pid == 0){ //Child process.
    write(STDOUT_FILENO, "world!", 6);
  }
  if (pid > 0){ //Parent process.
    write(STDOUT_FILENO, "Hello ", 6);
  }
}

void parentThenChild(void){
  pid_t pid = fork();
  if (pid == -1) perror("fork");
  if (pid > 0){ //Parent process.
    write(STDOUT_FILENO, "Hello ", 6);
  }
  if (pid == 0){ //Child process.
    write(STDOUT_FILENO, "world!", 6);
  }
}

int main(void){
  //childThenParent();
  parentThenChild();
}
