#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

//Exercise 7.
int main(int argc, char *argv[]){
  char prog[20];

  /* This excerpt of code replaces the image in memory of this process for the image
   * of a executable file passed on the arguments.
   */
  sprintf(prog, "%s.c", argv[1]);
  execlp("gcc", "gcc", prog, "-Wall", "-o", argv[1], NULL);
  printf("Failed to compile!");
  exit(-1);
}
