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

/*This program take input in the format:
 * <e|d><m>,<c>,<data>\n
 * and either encrypts or decrypts the data
 * option specified with the LCG keys m and c */
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
          lineStart = false;
          c = getchar();
        }
        else if(c == 'd')
        {
          encrypt = false;
          lineStart = false;
          c = getchar();
        }
        else
        {
          printf("%5d) Error\n", lineCount);
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
        }
      }
      if(c == ',')
      {
        delimCount++;
        i = 0;
        c = getchar();
      }
      /*scanning for m*/
      if(delimCount == 0)
      {
        lcg_m[i] = (c);
        i++;
        if(i > 20)
        {
          printf("%5d) Error\n", lineCount);
        }
      }
      /*scanning for c*/
      if(delimCount == 1)
      {
        lcg_c[i] = (c);
        i++;
        if(i > 20)
        {
          printf("%5d) Error\n", lineCount);
        }
      }
      /*generates the lcg and the encryps or decrypts*/
      if(delimCount == 2)
      {
        if(lcg.m == 0)
        {
          lcgm = strtoul(lcg_m, NULL, 10);
          lcgc = strtoul(lcg_c, NULL, 10);
          lcg = makeLCG(lcgm,lcgc);
          if(!lcg.m && !lcg.c && !lcg.a && !lcg.x)
          {
            printf("%5d) Error\n", lineCount);
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
          }
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
            if(c == '*')
            {
              c = getchar();
              if(c == '*')
              {
                cipherText = '*';
              }
              else if(c == '&')
              {
                cipherText = 127;
              }
              else
              {
                cipherText = (c - '@');
              }
              cipherText = cipherText ^ (getNextRandomValue(&lcg) % 128);
            }
            else
            {
              cipherText = c ^ (getNextRandomValue(&lcg) % 128);
            }
            printf("%c", (char)cipherText);
            c = getchar();
          }
          printf("\n");
        }

      }

    }
    return 0;
  }
