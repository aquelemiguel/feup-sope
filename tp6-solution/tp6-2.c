#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define STDERR 2
#define NUMITER 10000

int remainingChars = 50000, thread1 = 0, thread2 = 0;

//Exercise 2.
void *thrfunc(void *arg){
  fprintf(stderr, "Starting thread %s\n", (char*) arg);
  *((int *) arg) = 0; //Casts arg to integer pointer and dereferences it.

  while(remainingChars > 0){
    write(STDERR, "X", 1);
    remainingChars--;
    *((int *)arg) += 1; //Increments this thread's count.
  }
  return NULL;
}

int main(){
  pthread_t ta, tb;

  pthread_create(&ta, NULL, thrfunc, &thread1);
  pthread_create(&tb, NULL, thrfunc, &thread2);

  pthread_join(ta, NULL);
  pthread_join(tb, NULL);

  printf("\nThread 1: %d\nThread 2: %d\nTotal: %d\n", thread1, thread2, thread1+thread2);
  return 0;
}
//Had to write 'gcc -o tp6-1 -Wall tp6-1.c -pthread' to compile.
