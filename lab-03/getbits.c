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

int main(int argc, char const *argv[])
{
  unsigned  x;
  int c, p, n, xpnFlag, bits;
  int numericalValue, concatenatedValue;
  c = x = p = n = xpnFlag = bits = 0;
  numericalValue =  concatenatedValue = 0;

  while ((c = getchar()) != EOF)
  {
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
            xpnFlag++;
            break;
          }
          if(xpnFlag == 1)
          {
            p = concatenatedValue;
            xpnFlag++;
            break;
          }
        }
      }
      else
      {
        n = concatenatedValue;
        xpnFlag = 0;
      }
    }
    else
    {
    numericalValue = c - '0';
    concatenatedValue = ((concatenatedValue * 10) + numericalValue);
    }
    bits = getbits(x, p, n);
    printf("getbits(x=%u, p=%d, n=%d) = %d\n", x, p, n, bits);
  }

  return 0;
}

/*
 * to get numberic value scnning in char by char
 * 10*0+1->1
 * 10*1+1->12
 * 10*12+3->123
 */
