#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  printf("Hello World (PID:%d) \n", (int)getpid());
  int rc = fork();
  if (rc < 0) {
    printf("fork err\n");
    exit(1);
  } else if (rc == 0) {
    printf("Hello imma child PI:D%d \n", (int)getpid());
  } else {
    int wc = wait(NULL);  // parent will wait until child terminates
                          // prog comes here and stops; child starts running and
                          // terminates; then parent is brought back to life;
    printf("Hello imma parent %d WC:%d PID:%d \n", rc, wc, (int)getpid());
  }

  return 0;
}
