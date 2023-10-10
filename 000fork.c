#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("Hello World PID:%d:", (int)getpid());
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("Hello, I am child PID:%d\n", (int)getpid());
  } else {
    printf("Hello, I am parent of %d PID:%d\n", rc, (int)getpid());
  }

  if (rc) printf("parent\n");
  return 0;
}
