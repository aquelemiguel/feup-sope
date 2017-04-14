#include <termios.h>
#include <unistd.h>
#include <string.h>

//Exercise 1.
#define MAX_PASSWORD_LENGTH 16

int main(){
  struct termios oldterm, newterm;
  char password[MAX_PASSWORD_LENGTH], token, echo = '*';

  write(STDOUT_FILENO, "\nPassword: ", 11);

  tcgetattr(STDIN_FILENO, &oldterm); //Fills oldterm with standard input.
  newterm = oldterm;
  newterm.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON); //Local flags reset for echoing to console.
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &newterm); //Instantly alters standard input with the new settings.

  int i = 0;
  for (; i < MAX_PASSWORD_LENGTH; i++){
    read(STDIN_FILENO, &token, 1);
    if (token == '\n') break;
    password[i] = token;
    write(STDOUT_FILENO, &echo, 1); //Outputs one asterisk.
  }
  password[i] = 0; //Null termination character.

  tcsetattr(STDIN_FILENO, TCSANOW, &oldterm); // Resets console.
  write(STDOUT_FILENO, "\nYou inputted ", 14);
  write(STDOUT_FILENO, password, strlen(password));
  write(STDOUT_FILENO, ".\n\n", 3);

}
