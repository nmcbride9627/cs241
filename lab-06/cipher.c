#include <stdio.h>
#include "lcg.h"

int main(int argc, char const *argv[]) {
  unsigned long primes[64];
  findUniquePrimeFactors(30030, primes);
  return 0;
}
