#include <stdio.h>
#include <unistd.h>
int main() {
  // print the pid and ppid first
  printf("Pid %d", getpid());
  printf("PPid %d", getppid());
  // now call fork
  pid_t p = fork();
  if (p == 0) { // this pid is the pid of the child; fork returns the pid othe child so pid
    printf("CHILD: PID=  %d", getpid());
    printf("PARENT: PPID = %d", getppid());
  }
}
