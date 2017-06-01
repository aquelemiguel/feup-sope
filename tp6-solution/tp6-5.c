#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Exercise 5.
struct Operation {
  int x, y;
  char* op;
}

void *thread_handler(void *s){
  struct Operation thisStruct = *(Operation *) s;
  pthread_exit(NULL);
}

int main(void){
  int x, y;
  struct Operation o;

  printf("X and Y: ");
  scanf("%i %i", x, y);

  o.x = x; o.y = y;
  o.op = "add"; pthread_create(1, NULL, thread_handler, o);
  o.op = "sub"; pthread_create(2, NULL, thread_handler, o);
  o.op = "mul"; pthread_create(3, NULL, thread_handler, o);
  o.op = "div"; pthread_create(4, NULL, thread_handler, o);

}
