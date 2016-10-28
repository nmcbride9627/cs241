#include <stdio.h>
#include "lcg.h"
void findUniquePrimeFactors(unsigned long n, unsigned long primes[64])
{
  int i = 0;
  int testDivisor = 2;

  while(i < 64)
  {
    if(testDivisor * testDivisor > n)
    {
      if(n != 1)
      {
        primes[i] = n;
        i++;
      }
    }
    if(n / testDivisor == 0)
    {
      primes[i] = testDivisor;
      i++;
      while(n % testDivisor == 0)
      {
        n /= testDivisor;
      }
    }
    else
    {
      testDivisor++;
    }
  }
}

struct LinearCongruentialGenerator makeLCG(unsigned long m, unsigned long c)
{
  struct LinearCongruentialGenerator lcg;
  unsigned long primes[64];
  unsigned long p;
  int i = 0;

  lcg.x = c;
  findUniquePrimeFactors(m, primes);
  printf("Dunction call\n");
  while(primes[i])
  {
    p *= primes[i];
    i++;
  }

  lcg.m = m;
  lcg.c = c;
  if(m%4 == 0)
  {
    lcg.a = 1 + 2*p;
  }
  else
  {
    lcg.a = 1 + p;
  }
  return lcg;
}

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
