#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  printf("this is the parent");
  pid_t pid = fork(); // this is what saves the pid of the child in pid
  // create a child process that runs ls -a -l
  // child process "runs" means it calls exec
  if (pid) { // this is checking is the pid of the child is anyhting other than 0
             // PARENT
    int wstatus = 0;
    // execlp("ls", "ls", "-a", "-l", NULL);
    if (waitpid(pid, &wstatus, 0) == -1) {
      // this is if the child did not terminate normally
      // this is error line
      // what does perror do? print error message
      perror("waitpid");
      exit(EXIT_FAILURE);
    }
    if (WIFEXITED(wstatus)) {
      // this is why did the child TERMINATE
      printf("child exited with the status: %d\n", wstatus);
    } else {
      printf("child did not terminate normally");
    }

  } else {
    // this is the else to the if(pid) bc if pid = to anything other than 0 then??
    // if pid==0 that means it is the child process
    // CHILD
    //
    if (execlp("ls", "ls", "-a", "-l", NULL) == -1) {
      // so that means if child didnt run??
      perror("execlp");
      exit(EXIT_FAILURE);
    }
  }
}
