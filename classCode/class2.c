#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
  char *trial = "Hello\n";
  for (int i = 0; i < 4; i++) {
    printf("%c", trial[i]);

    sleep(8);
  }
  printf("wake up wake up wake up");
}
