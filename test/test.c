#include <stdio.h>

int main(int argc, char const *argv[]) {
  char c = 'm';
  char* p = &c;
  char** q = &p;

  q[0][0]++;
  printf("%c\n", c);
  return 0;
}
