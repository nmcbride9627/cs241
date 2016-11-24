/**********************/
/* Nathaniel McBride	*/
/* November 22, 2016	*/
/* CS-241-002				  */
/**********************/

#include <stdio.h>
#include <stdbool.h>

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

/* This program takes two file names as command line arguments
 * and hides a file from stdin in the last two bits of pixel
 * and padding data of a .bmp */
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

  int i;
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
  rowSize = pixelWidth*3;
  rowPadding = (4 - (rowSize % 4)) % 4;
  rowSize += rowPadding;

  /* write header to output file */
  fwrite(header, 1, sizeof(header), out);

  /* Iterate over pixel data 4 bytes at a time
   * changing last two bits of each byte with two
   * bits of character data */
  for(i = 0; i < pixelHeight * rowSize; i+=4)
  {
    unsigned char bytes[4];
    unsigned char mask = 0xFC;

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
        bytes[0] |= ((c >> 6) & 3);
        bytes[1] |= ((c >> 4) & 3);
        bytes[2] |= ((c >> 2) & 3);
        bytes[3] |= (c & 3);
      }
    }
    fwrite(&bytes, 1, 4, out);
  }
  fclose(in);
  fclose(out);
  return 0;
}
