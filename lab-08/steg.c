/**********************/
/* Nathaniel McBride	*/
/* November 22, 2016	*/
/* CS-241-002				  */
/**********************/

#include <stdio.h>
#include <stdbool.h>

/****************************************************************************/
/* This function copies 4 bytes from an int to an unsigned char array where */
/*   the least significant byte of the int is placed in the first element   */
/*   of the array.                                                          */
/****************************************************************************/
void copyIntToAddress(int n, unsigned char bytes[])
{
  bytes[0] = n & 0xFF;
  bytes[1] = (n >>  8) & 0xFF;
  bytes[2] = (n >> 16) & 0xFF;
  bytes[3] = (n >> 24) & 0xFF;
}

/**********************************************************************/
/* Take 4 bytes from an unsigned char array and assemble them into an */
/* int where the first element of the array is the least significant  */
/* byte of the int.                                                   */
/**********************************************************************/
int getIntFromArray(unsigned char bytes[])
{
  int n =
    bytes[0] |
    bytes[1] << 8 |
    bytes[2] << 16 |
    bytes[3] << 24;
  return n;
}

int main(int argc, char* argv[])
{
  char* infilename = argv[1];
  char* outfilename = argv[2];

  unsigned char header[54];

  FILE* in = fopen(infilename, "rb");
  FILE* out = fopen(outfilename, "wb");

  int pixelWidth;
  int pixelHeight;
  int rowSize;
  int rowPadding;

  int i, j;
  char c;
  bool endOfFile = false;


  /* read header into array */
  fread(header, 1, 54, in);

  /*correct number of arguments?*/
  if(argc != 3)
  {
    printf("Error: Bad arguments\n");
    return 1;
  }

  /* is this really a bitmap? */
  if(header[0] != 'B' || header[1] != 'M')
  {
    printf("Input file is not a bitmap\n");
  }

  /* Is the header size what we expect? */
  if(getIntFromArray(&header[10]) != 54)
  {
    printf("Unexpected header size\n");
  }

  /* How many bits per pixel? Expecting 24*/
  if(!(header[28] == 24 && header[29] == 0))
  {
    printf("Unexpected number of bits/pixel\n");
  }

  pixelWidth = getIntFromArray(&header[18]);
  pixelHeight = getIntFromArray(&header[22]);

  /* compute row padding */
  rowSize = pixelWidth*4;
  rowPadding = (4 - (rowSize % 4)) % 4;
  rowSize += rowPadding;

  /* write header to output file */
  fwrite(header, 1, sizeof(header), out);

  /* TODO */
  for(i = 0; i < pixelHeight; ++i)
  {
    for(j = 0; j < pixelWidth; ++j)
    {
      unsigned char bytes[4];
      unsigned char mask = 0xFC;

      /* color order is BGR */
      fread(&bytes, 1, 4, in);
      if(!endOfFile)
      {
        bytes[0] &= mask;
        bytes[1] &= mask;
        bytes[2] &= mask;
        bytes[3] &= mask;

        c = getchar();
        if(c == EOF)
        {
          endOfFile = true;
        }
        else
        {
          bytes[0] = bytes[0] | ((c >> 6) & 3);
          bytes[1] = bytes[1] | ((c >> 4) & 3);
          bytes[2] = bytes[2] | ((c >> 2) & 3);
          bytes[3] = bytes[3] | (c & 3);
        }
      }
      fwrite(&bytes, 1, 4, out);
    }

    /* handle end of row padding */
    fseek(in, rowPadding, SEEK_CUR);
    for(j = 0; j < rowPadding - 1; ++j)
    {
      putc(0, out);
    }
  }
  fclose(in);
  fclose(out);
  return 0;
}
