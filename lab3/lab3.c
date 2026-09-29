#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
  char *user = NULL;
  size_t size = 0;
  char *inputs[5] = {NULL};
  while (user == NULL) {
    int i = 0;
    while (i < 5) {
      printf("Enter an input:\n");
      ssize_t p = getline(&user, &size, stdin);
      if (p == -1) {
        break;
      }

      // okay till here it is storing exactly what the user is putting in
      // this is where the problem comes up
      inputs[i] = user;
      user = NULL;
      i++;
      if (i == 5) {
        for (int j = 0; j < 5; j++) {
          printf("%s", inputs[j]);
        }
      }
    }
    user = NULL;
    // for (int i = 0; i < 5; i++) {
    // printf("%s", inputs[i]);
    //}
  }
}
