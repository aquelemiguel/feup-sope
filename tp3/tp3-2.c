#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Exercise 2.
int main(void){
  //write(STDOUT_FILENO, "1", 1);
  //printf("1");
  printf("1\n");
  if (fork() > 0){
    //write(STDOUT_FILENO, "2", 1);
    //printf("2");
    printf("2\n");
    //write(STDOUT_FILENO, "3", 1);
    //printf("3");
    printf("3\n");
  }else{
    //write(STDOUT_FILENO, "4", 1);
    //printf("4");
    printf("4\n");
    //write(STDOUT_FILENO, "5", 1);
    //printf("5");
    printf("5\n");
  }
  //write(STDOUT_FILENO, "\n", 1);
  printf("\n");
  return 0;
}

/* write() calls produced 123;45 output.
 * printf() calls (without newline char) produced 123;145 output.
 * printf() calls (with newline char) produced 1;2;3;;4;5 output.
 */
