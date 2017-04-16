#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define MAX_LENGTH 256

struct Operands {
  int x, y;
};

//Exercise 1.
int main(void){
  int fd[2];
  pid_t pid;

  if (pipe(fd) == -1){ //Opens pipe.
    perror("Pipe error");
    exit(1);
  }
  if ((pid = fork()) == -1){
    perror("Fork error");
    exit(1);
  }
  if (pid > 0){ //Parent process.
    //int nums[2];
    //struct Operands op;
    char x[MAX_LENGTH], y[MAX_LENGTH];

    printf("x & y : ");

    //scanf("%i %i", &nums[0], &nums[1]);
    //scanf("%i %i", &op.x, &op.y);
    scanf("%s %s", x, y);

    close(fd[0]); //Closes read.

    //write(fd[1], nums, 2 * sizeof(int)); //Writes to 'child read' an array of two integers.
    //write(fd[1], &op, 2 * sizeof(op)); //Struct should have the same size of two ints, but for the sake of consistency.
    write(fd[1], x, MAX_LENGTH);
    write(fd[1], y, MAX_LENGTH);

    close(fd[1]); //Closes write.
  }
  if (pid == 0){ //Child process.
    //int nums[2];
    //struct Operands op;
    char x[MAX_LENGTH], y[MAX_LENGTH];
    int lastDig, xInt, yInt; //Didn't bother to save as double. This being int results in integer quotient.

    close(fd[1]); //Closes write.

    //read(fd[0], nums, 2 * sizeof(int)); //Reads the two integers from 'child read'.
    //read(fd[0], &op, 2 * sizeof(op));
    lastDig = read(fd[0], x, MAX_LENGTH); x[lastDig] = 0;
    lastDig = read(fd[0], y, MAX_LENGTH); y[lastDig] = 0;

    xInt = atoi(x); yInt = atoi(y);

    //printf("Sum: %i\nSub: %i\nMul: %d\nDiv: %d\n", nums[0] + nums[1], nums[0] - nums[1], nums[0] * nums[1], nums[0] / nums[1]);
    //printf("Sum: %i\nSub: %i\nMul: %d\nDiv: %d\n", op.x + op.y, op.x - op.y, op.x * op.y, op.x / op.y);
    printf("Sum: %i\nSub: %i\nMul: %d\nDiv: %d\n", xInt + yInt, xInt - yInt, xInt * yInt, xInt / yInt);
    close(fd[0]); //Closes read.
  }

}
