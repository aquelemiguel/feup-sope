#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

//Exercise 3.
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]){
  char buffer[BUFFER_SIZE];
  int des1 = open(argv[1], O_RDONLY);
  int des2 = open(argv[2], O_WRONLY | O_CREAT, 0644);

  if (argv[2] != NULL){
    dup2(des2, STDOUT_FILENO); //Redirects standard output to file.
  }

  int bytesRead = read(des1, buffer, BUFFER_SIZE);
  write(STDOUT_FILENO, buffer, bytesRead); //Outputs to standard output.

}
