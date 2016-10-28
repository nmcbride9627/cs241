#include <stdio.h>
#include "lcg.h"

int main(int argc, char const *argv[]) {
  unsigned long primes[64];
  findUniquePrimeFactors(11440, primes);
  return 0;
}
