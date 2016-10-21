/**********************/
/* Nathaniel McBride  */
/* October 17, 2016   */
/* CS-241-002         */
/**********************/

#include <stdio.h>
#include <string.h>

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
  if(argc != 4)
  {
    printf("ERROR: incorrect number of arguments\n%s", USAGE);
    return 1;
  }
  if(*++argv[1] == 'b')
  {
    binary = 1;
  }
  else if(*++argv[1] == 'd')
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

  return 0;
}
