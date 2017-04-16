#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define STDERR 2
#define NUMITER 10000

void *thrfunc(void *arg){
  int i;
  fprintf(stderr, "Starting thread %s\n", (char*) arg);
  for (i = 1; i <= NUMITER; i++) write(STDERR, arg, 1);
  return NULL;
}

//Exercise 1.
int main(){
  pthread_t ta, tb;

  //char one = '1', two = '2';
  int one = 1, two = 2; //This just prints gibberish.

  pthread_create(&ta, NULL, thrfunc, &one);
  pthread_create(&tb, NULL, thrfunc, &two);

  pthread_join(ta, NULL);
  pthread_join(tb, NULL);

  return 0;
}
//Had to write 'gcc -o tp6-1 -Wall tp6-1.c -pthread' to compile.
