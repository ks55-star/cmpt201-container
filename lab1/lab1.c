#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char *str = NULL;
  size_t size = 0;
  char *saveptr = NULL;
  while (str == NULL) {
    printf("Please enter some text: ");
    ssize_t userInput = getline(&str, &size, stdin);
    if (userInput == -1) {
      break;
    }
    char *token = strtok_r(str, " ", &saveptr);
    printf("Tokens: \n");
    while (token != NULL) {

      printf("%s \n", token);
      token = strtok_r(NULL, " ", &saveptr);
    }
    str = NULL;
  }
  free(str);
}
