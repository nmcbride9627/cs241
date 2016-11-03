#include "lcg.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
    int c, i = 0, delimCount = 0, lineCount = 0;
    unsigned long cipherText;
    char lcg_m[20], lcg_c[20];
    unsigned long lcgm, lcgc;
    bool lineStart = true;
    bool encrypt = true;
    struct LinearCongruentialGenerator lcg;

    while ((c = getchar()) != EOF)
    {
      if(lineStart && (c == 'e' || c == 'd'))
      {
        if(c == 'e')
        {
          encrypt = true;
        }
        if(c == 'd')
        {
          encrypt = false;
        }
      }
      else
      {
        /*TODO ERROR*/
      }
      if(c == ',')
      {
        delimCount++;
      }
      if(delimCount == 0)
      {
        lcg_m[i] = (c - '0');
        i++;
        if(i > 20)
        {
          i = 0;
        }
      }
      if(delimCount == 1)
      {
        lcg_c[i] = (c - '0');
        i++;
        if(i > 20)
        {
          i = 0;
        }
      }
      if(delimCount == 2)
      {
        if(lcg->m == 0)
        {
          lcgm = strtoul(lcg_m, NULL, 10);
          lcgc = strtoul(lcg_c, NULL, 10);
          lcg = makeLCG(lcgm,lcgc);
        }
        if(encrypt)
        {
          printf("%5d ", lineCount);
          while (c != EOF)
          {
            if(c == '\n')
            {
              delimCount = 0;
              lineStart = true;
              lineCount++;
              break;
            }
            cipherText = c ^ (getNextRandomValue(&lcg) % 128);
            printf("%lu", cipherText);
          }
          printf("\n");
        }

      }

    }
    return 0;
  }
