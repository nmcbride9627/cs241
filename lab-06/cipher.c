#include <stdio.h>
#include "lcg.h"

int main(int argc, char const *argv[]) {
  int i;
  struct LinearCongruentialGenerator lcg = makeLCG(2291092019019, 3);
  printf("LCG.m = %lu\n", lcg.m);
  printf("LCG.a = %lu\n", lcg.a);
  printf("LCG.c = %lu\n", lcg.c);
  printf("LCG.x = %lu\n", lcg.x);
  for(i = 0; i < 100; i++){
    printf("Next Random value = %lu\n", getNextRandomValue(&lcg));
  }
  return 0;
}
