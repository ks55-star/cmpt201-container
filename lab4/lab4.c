#define _DEFAULT_SOURCE
#define _ISOC99_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 64
struct header {
  uint64_t size;
  struct header *next;
};
#define HEAP_SIZE 256
void handle_error(const char *s) {
  perror(s);
  exit(EXIT_FAILURE);
}
void print_out(char *format, void *data, size_t data_size) {
  char buf[BUF_SIZE];
  ssize_t len = snprintf(buf, BUF_SIZE, format,
                         data_size == sizeof(uint64_t) ? *(uint64_t *)data : *(void **)data);
  if (len < 0) {
    handle_error("snprintf");
  }
  write(STDOUT_FILENO, buf, len);
}
int main() {
  // increase heap size
  //  intptr_t increment = 256;
  char *more = sbrk(256);
  //  printf("address or sbrk's variable more %p\n", more);
  struct header *myblock = (struct header *)more;
  myblock->size = 128;
  myblock->next = NULL;
  printf("first block:      %p\n", myblock);

  struct header *secondblock = (void *)myblock + 128;
  secondblock->size = 128;
  secondblock->next = NULL;
  printf("second block:     %p\n", secondblock);
  // this is the address AFTER the first header
  char *address = (void *)(myblock + 1);
  printf("first block size: %lu\n", myblock->size);
  printf("first block next: %p\n", myblock->next);
  printf("second block size:%lu\n", secondblock->size);
  printf("second block next:%p\n", secondblock->next);
  // i need to know the address of the pointer after struct
  while (address < secondblock) {
    size_t i = 112;
    memset(address, 0, i);
    //    print_out("where the 0's start %p\n", &address, sizeof(&address));
    printf("%d\n", *address);
    address += 1;
  }
  address =
      (void *)(secondblock + 1); // this is literally secondblock address + 1 header's struct szie
  while (address < (void *)secondblock + 128) {
    size_t i = 112;
    memset(address, 1, i);
    address += 1;
    printf("%d\n", *address);
  }
}
