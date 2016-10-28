#include <stdio.h>
#include "lcg.h"

void findUniquePrimeFactors(unsigned long n, unsigned long primes[64]);
int main(int argc, char const *argv[]) {
  unsigned long primes[64];
  unsigned long n = 490;
  int i = 0;
  findUniquePrimeFactors(n, primes);
  while(primes[i])
  {
    printf("primes[%d] = %lu\n",i, primes[i]);
    i++;
  }
  return 0;
}
