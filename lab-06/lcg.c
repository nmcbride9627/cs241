/**********************/
/* Nathaniel McBride  */
/* November 4, 2016   */
/* CS-241-002         */
/**********************/
#include <stdio.h>
#include "lcg.h"
/* This function finds unique prime factors of a number
 * returns an array of the prime factors with max of 64*/
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
      return;
    }
    if(n % testDivisor == 0)
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
/*This function generated the LCG given m and c*/
struct LinearCongruentialGenerator makeLCG(unsigned long m, unsigned long c)
{
  struct LinearCongruentialGenerator lcg;
  unsigned long primes[64] = {0};
  unsigned long p = 1;
  int i = 0;

  findUniquePrimeFactors(m, primes);
  while(primes[i])
  {
    p *= primes[i];
    i++;
  }

  lcg.x = c;
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

  if(lcg.m <= 0 || lcg.a <= 0 || lcg.a >= lcg.m || lcg.c < 0 || lcg.c >= lcg.m)
  {
    lcg.m = 0;
    lcg.a = 0;
    lcg.c = 0;
    lcg.x = 0;
  }
  return lcg;
}
/*This function returns the next value from a LCG*/
unsigned long getNextRandomValue(struct LinearCongruentialGenerator* lcg)
{
  unsigned long x = lcg->x;
  lcg->x = (lcg->a*lcg->x + lcg->c) % lcg->m;
  return x;
}
