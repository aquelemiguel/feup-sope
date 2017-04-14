#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <sys/times.h>
/*
// 2a
int main(void){
  printf("Hello world!\n");
  return 0;
}

// 3b
int main(void){
  printf("Hello world!\n");
  return 1;
}

// 4a
int main(int argc, char* argv[]){
  char name[256] = "";
  for (int i = 1; i < argc; i++){
    strcat(name, argv[i]);
    if (i+1 < argc) strcat(name, " ");
  }
  printf("Hello, %s!", name);
}

// 4b
int main(int argc, char* argv[]){
  char name[256] = "";
  int displayLoops = atoi(argv[argc - 1]);

  for (int i = 1; i < argc - 1; i++){
    strcat(name, argv[i]);
    if (i+1 < argc) strcat(name, " ");
  }
  for (int i = 0; i < displayLoops; i++){
    printf("Hello, %s!\n", name);
  }
}

// 5a
int main(int argc, char* argv[], char* envp[]){
  for (size_t i = 0; envp[i] != NULL; i++){ //envp[] is terminated by NULL pointer.
    printf("%s\n", envp[i]);
  }
}

// 5b
int main(int argc, char* argv[], char* envp[]){
  char username[256];
  for (size_t i = 0; envp[i] != NULL; i++){
    if (strstr(envp[i], "USER=") != NULL){
      strncpy(username, envp[i] + 5, strlen(envp[i]) - 5);
      username[strlen(envp[i]) - 5] = '\0';
    }
  }
  printf("Hello, %s!", username);
}


// 5c
int main(int argc, char* argv[], char* envp[]){
  printf("Hello, %s!", getenv("USER"));
}

// 5d
int main(int argc, char* argv[], char* envp[]){
  printf("Hello, %s!", getenv("USER_NAME")); // $export USER_NAME=aquelemiguel; $unset USER_NAME to delete.
}

// 6e
#define BUF_LENGTH 256
int main(void){
  FILE *src, *dst;
  char buf[BUF_LENGTH]; // Case sensitive.
  if ((src = fopen("infile.txt", "r")) == NULL){
    printf("errno value: %i", errno);
    exit(1); // Termination code at first run.
  }
  if ((dst = fopen("outfile.txt", "w")) == NULL){
    exit(2);
  }
  while ((fgets(buf, 64, src)) != NULL){ // MAX is parameter n.
    fputs(buf, dst);
  }
  fclose(src);
  fclose(dst);
  exit(0);
}

// 6h
#define BUF_LENGTH 256
int main(int argc, char* argv[]){
  if (argc != 3){
    printf("Usage: executable_name file1 file2");
    exit(1);
  }

  FILE *src, *dst;
  char buf[BUF_LENGTH];
  if ((src = fopen(argv[1], "r")) == NULL) exit(1);
  if ((dst = fopen(argv[2], "w")) == NULL) exit(2);
  while ((fgets(buf, 64, src)) != NULL){
    fputs(buf, dst);
  }
  fclose(src); fclose(dst);
  exit(0);
}

// 7a
static void exitHandler1(void){
  printf("Executing exit handler 1...");
}
static void exitHandler2(void){
  printf("Executing exit handler 2...");
}
int main(void){
  atexit(exitHandler2);
  atexit(exitHandler1); // Mind the order. Stack-like.
  printf("Main done!");
}
*/
// Alínea 8)
int main(int argc, char* argv[]){
  int n1 = atoi(argv[1]), n2 = atoi(argv[2]), randNum = INT_MAX;
  struct tms buf;
  clock_t elapsedLoop;
  int ticksPerSecond = sysconf(_SC_CLK_TCK);

  time_t t; srand((unsigned) time(&t)); // Randomizes the seed.

  for (size_t i = 0; randNum != n2; i++){
    printf("%lu : %d\n", i, randNum = rand() % n1);
  }
  elapsedLoop = times(&buf); // Not sure if time is correct, but looks like it.

  double userElapsed = (double)buf.tms_utime / (double)ticksPerSecond;
  double systemElapsed = (double)buf.tms_stime / (double)ticksPerSecond;

  printf("\nUser time: %gs elapsed", userElapsed);
  printf("\nSystem time: %gs elapsed", systemElapsed);
}
