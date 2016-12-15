#include <stdio.h>

int main(int argc, char const *argv[]) {
  char c = 'm';
  char* p = &c;
  char** q = &p;

  ++(**q);
  printf("%c\n", c);
  return 0;
}
