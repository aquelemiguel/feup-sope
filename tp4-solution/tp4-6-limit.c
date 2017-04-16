#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

//Exercise 6.
int main(int argc, char* argv[]){
  if (argc != 4){
    printf("Incorrect usage.\n");
    exit(1);
  }
  if (execl(argv[2], argv[1], argv[3], NULL) == -1){
    perror("Couldn't execute prog");
  }
}
