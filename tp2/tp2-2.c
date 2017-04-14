#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

//Exercise 2.
#define BUFFER_SIZE 1024

//Using C library only.
void copyC(char* src, char* dest){
  FILE *srcptr, *destptr;
  char buffer[BUFFER_SIZE];

  srcptr = fopen(src, "r"); //Opens source file for reading.
  destptr = fopen(dest, "w"); //Opens destination file for writing.

  size_t charsRead = fread(buffer, 1, BUFFER_SIZE, srcptr);
  fwrite(buffer, 1, charsRead, destptr);

  fclose(srcptr); fclose(destptr);
}

//Using direct OS calls.
void copyOS(char* src, char* dest){
    char buffer[BUFFER_SIZE];

    int srcDes = open(src, O_RDONLY); //Opens source file for reading.
    int destDes = open(dest, O_WRONLY | O_CREAT, 0644); //If file doesn't exist, it's created.

    ssize_t bytesRead = read(srcDes, buffer, BUFFER_SIZE);
    write(destDes, buffer, bytesRead);

    close(srcDes); close(destDes); //Close the files using the file descriptor.
}

int main(int argc, char* argv[]){
  //copyC(argv[1], argv[2]);
  copyOS(argv[1], argv[2]);
}
