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
  unsigned  x, bits;
  int c, p, n, xpnFlag;
  int numericalValue, concatenatedValue;
  c = x = p = n = xpnFlag = bits = 0;
  numericalValue =  concatenatedValue = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == '\n')
    {
      /*newline logic*/
      printf("getbits(x=%u, p=%d, n=%d) = %u\n", x, p, n, getbits(x, p, n));
    }
    else
    {
      /*not on a new line*/
      if (c != ',')
      {
        printf("%d\n", numericalValue);
      } else {
        /* code */
      }
    }

      /* cycles where to store numericalValue between
       * x, p, and n and stores repectively*/
    if(c == ',' || c == '\n')
    {
      if(c == ',')
      {
        {
          if(xpnFlag == 0)
          {
            x = concatenatedValue;
            concatenatedValue = 0;
            xpnFlag++;
          }
          if(xpnFlag == 1)
          {
            p = concatenatedValue;
            concatenatedValue = 0;
            xpnFlag++;
          }
        }
      }
      else
      {
        n = concatenatedValue;
        concatenatedValue = 0;
        xpnFlag = 0;
      }
    }
    else
    {
    numericalValue = c - '0';
    concatenatedValue = ((concatenatedValue * 10) + numericalValue);
    }
  }

  return 0;
}

/*
 * to get numberic value scnning in char by char
 * 10*0+1->1
 * 10*1+1->12
 * 10*12+3->123
 */
