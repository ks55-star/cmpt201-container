#include <stdio.h>
#include <unistd.h>
int main() {
  printf("Hi\n");
  pid_t pid = fork();
  execlp("/bin/ls", "ls -a");
  if (pid == 0) {
    execlp("/bin/ls", "ls -alh");
  }
  printf("This should not print\n");
}
