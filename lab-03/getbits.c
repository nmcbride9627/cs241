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
  printf("%u\n",getbits(127, 2, 1));
  /*
  unsigned  x, bits;
  int c, p, n, xpnFlag;
  int numericalValue, concatenatedValue;
  c = x = p = n = xpnFlag = bits = 0;
  numericalValue =  concatenatedValue = 0;

  while ((c = getchar()) != EOF)
  {

      * cycles where to store numericalValue between
       * x, p, and n and stores repectively*
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
*/
  return 0;
}

/*
 * to get numberic value scnning in char by char
 * 10*0+1->1
 * 10*1+1->12
 * 10*12+3->123
 */
