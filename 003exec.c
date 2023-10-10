#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  printf("Hello World PID:%d\n", getpid());

  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(0);
  } else if (rc == 0) {
    printf("Hello World from child rc:%d %d\n", rc, (int)getpid());
    char *myargs[3];
    myargs[0] = strdup("wc");
    myargs[1] = strdup("p3.c");
    myargs[2] = NULL;
    execvp(myargs[0], myargs);
    printf("This shouldn't print out");
    free(myargs[0]);
    free(myargs[1]);
  }
  if (rc) {
    int wc = wait(NULL);
    printf("Hello I am parent of rc:%d wc:%d %d\n", rc, wc, (int)getpid());
  }

  return 0;
}
