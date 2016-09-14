/*********************/
/* Nathaniel McBride */
/* September 16, 2016 */
/* CS-241-002        */
/*********************/
#include <stdio.h>
#include <stdbool.h>

/*getbits: get n bits from position p*/
unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p+1-n)) & ~(~0 << n);
}
int bitCount(unsigned x)
{
  int b;
  for(b = 0; x != 0; x >>= 1)
  {
    b++;
  }
  return b;
}
/*gets numerical value of a number*/
int getNumericalValue(int x)
{
  return x - '0';
}

/*TODO add comments*/
/*TODO fix error messages*/
int main(int argc, char const *argv[])
{
  int c, p, n = 0;
  unsigned  x = 0;
  unsigned long concatenatedValue = 0;
  bool xTooBig = false;

  while ((c = getchar()) != EOF)
  {
    /*new line check*/
    if (c == '\n')
    {
      /*set value for n newline is its delimiter*/
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
      /*print statements*/
      if (xTooBig)
      {
        printf("Error: value out of range\n");
        xTooBig = false;
      }
      else if (n > p+1)
      {
        printf("Error: too many bits requested from position\n");
      }
      else if(p + 1 > bitCount(x))
      {
        printf("Error: number of bits out of range\n");
      }
      else
      {
        printf("getbits(x=%u, p=%d, n=%d) = %u\n", x, p, n, getbits(x, p, n));
      }
      x = p = n = 0;
    }
    /*not on a new line*/
    else
    {
      if (c != ',')
      {
        concatenatedValue = (concatenatedValue * 10) + getNumericalValue(c);
      }
      /*set values for x and p if delimiter is found*/
      else {
        if(x == 0)
        {
          if (concatenatedValue > 0xFFFFFFFF)
          {
            xTooBig = true;
          }
          else
          {
            x = concatenatedValue;
            concatenatedValue = 0;
          }
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
