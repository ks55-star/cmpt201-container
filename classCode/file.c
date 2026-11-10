#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
  const char *tmp = "tmp.c";
  int file = open(tmp, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  const void *buf = "is this being written?";
  ssize_t byteswritten = write(file, buf, 22);
}
