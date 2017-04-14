#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

//Exercise 4.
#define BUFFER_SIZE 1024
#define STUDENTS_NUM 3

struct Student{
  char name[64];
  char grade[64];
};

int main(){
  int des = open("output.txt", O_RDWR | O_APPEND | O_CREAT, 0644);
  char buffer[BUFFER_SIZE];

  for (size_t i = 0; i < STUDENTS_NUM; i++){ //Could've figured out a more elegant way to loop, but this'll do.
    struct Student s;

    write(STDOUT_FILENO, "Name: ", 6);
    s.name[read(STDIN_FILENO, s.name, BUFFER_SIZE)] = 0; //Reads name and sets the null char.

    write(des, "Name: ", 6); //Writes to file.
    write(des, s.name, strlen(s.name));

    write(STDOUT_FILENO, "Grade: ", 7);
    s.grade[read(STDIN_FILENO, s.grade, BUFFER_SIZE)] = 0; //Reads grade and sets the null char.

    write(des, "Grade: ", 7);
    write(des, s.grade, strlen(s.grade));

  }
  close(des);

}
