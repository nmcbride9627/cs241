/**********************/
/* Nathaniel McBride  */
/* November 4, 2016   */
/* CS-241-002         */
/**********************/
#include "lcg.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]) {
    int c, i = 0, delimCount = 0, lineCount = 1;
    unsigned long cipherText;
    char lcg_m[20] = {0}, lcg_c[20]= {0};
    unsigned long lcgm, lcgc;
    bool lineStart = true;
    bool encrypt = true;
    struct LinearCongruentialGenerator lcg = {0,0,0,0};

    while ((c = getchar()) != EOF)
    {
      if(lineStart)
      {
        if(c == 'e')
        {
          encrypt = true;
          c = getchar();
        }
        else if(c == 'd')
        {
          encrypt = false;
          c = getchar();
        }
        else
        {
          printf("%5d) Error", lineCount);
          while (c != EOF)
          {
            if(c == '\n')
            {
              delimCount = 0;
              lineStart = true;
              lineCount++;
              lcg.m = 0;
              memset(&lcg_c, 0, 20);
              memset(&lcg_m, 0, 20);
              break;
            }
          }
        }
      }
      else
      {
        /*TODO ERROR*/
      }
      if(c == ',')
      {
        delimCount++;
        i = 0;
        c = getchar();
      }
      if(delimCount == 0)
      {
        lcg_m[i] = (c);
        i++;
        if(i > 20)
        {
          /*TODO ERROR*/
        }
      }
      if(delimCount == 1)
      {
        lcg_c[i] = (c);
        i++;
        if(i > 20)
        {
          /*TODO ERROR*/
        }
      }
      if(delimCount == 2)
      {
        if(lcg.m == 0)
        {
          lcgm = strtoul(lcg_m, NULL, 10);
          lcgc = strtoul(lcg_c, NULL, 10);
          lcg = makeLCG(lcgm,lcgc);
        }
        if(encrypt)
        {
          printf("%5d) ", lineCount);
          while (c != EOF)
          {
            if(c == '\n')
            {
              delimCount = 0;
              lineStart = true;
              lineCount++;
              lcg.m = 0;
              memset(&lcg_c, 0, 20);
              memset(&lcg_m, 0, 20);
              break;
            }
            cipherText = c ^ (getNextRandomValue(&lcg) % 128);
            if(cipherText < 32)
            {
              printf("*%c", (char)('@'+cipherText));
            }
            else if(cipherText == 127)
            {
              printf("*&");
            }
            else if(cipherText == '*')
            {
              printf("**");
            }
            else
            {
              printf("%c", (char)cipherText);
            }
            c = getchar();
          }
          printf("\n");
        }
        else if(!encrypt)
        {
          /*TODO decrypt*/
          while (c != EOF)
          {
            if(c == '\n')
            {
              delimCount = 0;
              lineStart = true;
              lineCount++;
              lcg.m = 0;
              memset(&lcg_c, 0, 20);
              memset(&lcg_m, 0, 20);
              break;
            }
            c = getchar();
          }
          printf("Decrypt line\n");
        }

      }

    }
    return 0;
  }
