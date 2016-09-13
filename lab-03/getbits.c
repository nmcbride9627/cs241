/*********************/
/* Nathaniel McBride */
/* September 16, 2016 */
/* CS-241-002        */
/*********************/
#include <stdio.h>

/*getbits: get n bits from position p*/
unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p+1-n)) & ~(~0 << n);
}
int getNumericalValue(int x)
{
  return x - '0';
}
int main(int argc, char const *argv[])
{
  unsigned  x, test;
  int c, p, n;
  int concatenatedValue = 0;
  c = x = p = n = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == '\n')
    {
      if(n == 0)
      {
        n = concatenatedValue;
        concatenatedValue = 0;
      }
      else
      {
        perror("This shouldn't happen, something broke!");
        return 1;
      }
      if (n > p+1)
      {
        printf("Error: too many bits requested from position\n");
      }
      else if (x > sizeof(test))
      {
        printf("Error: position out of range\n");
      }
      else
      {
        printf("getbits(x=%u, p=%d, n=%d) = %u\n", x, p, n, getbits(x, p, n));
      }
      x = p = n = 0;
    }
    else
    {
      /*not on a new line*/
      if (c != ',')
      {
        concatenatedValue = (concatenatedValue * 10) + getNumericalValue(c);
      }
      else {
        if(x == 0)
        {
          x = concatenatedValue;
          concatenatedValue = 0;
        }
        else if (p == 0)
        {
          p = concatenatedValue;
          concatenatedValue = 0;
        }
        else
        {
          perror("This shouldn't happen, something broke!");
          return 1;
        }
      }
    }
  }
  return 0;
}

/* to get numberic value scanning in char by char
 * 10*0+1  -> 1
 * 10*1+1  -> 12
 * 10*12+3 -> 123 */
