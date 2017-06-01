#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREADS_TO_CREATE 5

//Exercise 4.
void *thread_handler(void *index){
  sleep(1);
  printf("My TID is %d.\n", *(int *) index);
  int returnValue = *(int *) index + 1; //This dereferencing causes some warnings, but works.

  pthread_exit(returnValue);
}

int main(void){
  pthread_t threads[THREADS_TO_CREATE];

  for (int i = 0; i < THREADS_TO_CREATE; i++){
    int returnCode;

    printf("Creating thread %d.\n", i); //For some reason, removing this printf won't display the handler prints.
    pthread_create(&threads[i], NULL, thread_handler, (void *) &i);

    pthread_join(threads[i], (void **) &returnCode); //Wait for this thread to complete before iterating again, save exit code to returnCode.
    printf("Thread %d exited with code %d.\n\n", i , returnCode);
  }

}
