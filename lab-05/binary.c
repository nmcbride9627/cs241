/**********************/
/* Nathaniel McBride  */
/* October 17, 2016   */
/* CS-241-002         */
/**********************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

unsigned long convertToDecimal(char *number)
{
  int num = strtoul(number, NULL, 2);
  unsigned long rem = 0, sum = 0, power = 0;

  while(num > 0)
  {
    rem = num % 10;
    num /= 10;
    sum += (rem * pow(2, power));
    power++;
  }
  return sum;
}

unsigned long convertToBinary(char *number)
{
  int num = strtoul(number, NULL, 10);
  unsigned long rem, sum = 0, power = 0;

  while(num > 0)
  {
    rem = num % 2;
    num /= 2;
    sum += (rem * power);
    power *= 10;
  }
  return sum;
}

void printDecimal(char *str, int length)
{
  printf("%s\n", str);
}

void printBinary(char *str, int length)
{
  printf("%s\n", str);
}

int main(int argc, char *argv[])
{
  const char *USAGE = "usage:\n"
    "./binary OPTION SIZE NUMBER\n"
    " OPTION:\n"
    "   -b    NUMBER is a binary and output will be in decimal.\n"
    "   -d    NUMBER is a decimal and output will be in binary.\n\n"
    " SIZE:\n"
    "   -8    input is an unsigned 8-bit integer.\n"
    "   -16   input is an unsigned 16-bit integer.\n"
    "   -32   input is an unsigned 32-bit integer.\n"
    "   -64   input is an unsigned 64-bit integer.\n\n"
    " NUMBER:\n"
    " number to be converted.\n";

  int binary = 0, decimal = 0, size = 0;
  unsigned long number;

  if(argc != 4)
  {
    printf("ERROR: incorrect number of arguments\n%s", USAGE);
    return 1;
  }
  if(strcmp(argv[1], "-b") == 0)
  {
    binary = 1;
  }
  else if(strcmp(argv[1], "-d") == 0)
  {
    decimal = 1;
  }
  else
  {
    printf("ERROR: argument 1 must be -b | -d\n%s", USAGE);
    return 1;
  }
  if(strcmp(argv[2], "-8") == 0)
  {
    size = 8;
  }
  else if(strcmp(argv[2], "-16") == 0)
  {
    size = 16;
  }
  else if(strcmp(argv[2], "-32") == 0)
  {
    size = 32;
  }
  else if(strcmp(argv[2], "-64") == 0)
  {
    size = 64;
  }
  else
  {
    printf("ERROR: argument 2 must be: -8 | -16 | -32 | -64\n%s", USAGE);
    return 1;
  }
  if(binary == 1)
  {
    char str[64];

    number = convertToDecimal(argv[3]);
    if(number == 0)
    {
      printf("ERROR: argument 3 is not a decimal integer\n");
      return 1;
    }
    sprintf(str, "%lu", number);
    printDecimal(str, size);
  }
  else if(decimal == 1)
  {
    char str[64];
    number = convertToBinary(argv[3]);
    if(number == 0)
    {
      printf("ERROR: argument 3 is not a decimal integer\n");
      return 1;
    }
    sprintf(str, "%lu", number);
    printBinary(str, size);
  }
  else
  {
    printf("ERROR: this shouldn't happen\n");
    return 1;
  }


  return 0;
}
