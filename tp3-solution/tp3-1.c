#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Exercise 1.
int global = 1;

int main(void){
  int local = 2;

  if (fork() > 0){ //Parent process.
    printf("PID = %d; PPID = %d\n", getpid(), getppid());
    global++;
    local--;
  } else { //Child process.
    printf("PID = %d; PPID = %d\n", getpid(), getppid());
    global--;
    local++;
  }
  printf("PID = %d - global = %d ; local = %d\n", getpid(), global, local);
  return 0;
}
