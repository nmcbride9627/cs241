/**********************/
/* Nathaniel McBride	*/
/* November 22, 2016	*/
/* CS-241-002				  */
/**********************/

#include <stdio.h>

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

  unsigned char header[54];

  FILE* in = fopen(infilename, "rb");

  int pixelWidth;
  int pixelHeight;
  int rowSize;
  int rowPadding;

  int i;

  fread(header, 1, 54, in);

  /*correct number of arguments?*/
  if(argc != 2)
  {
    printf("Error, bad arguments\n");
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

  /* Read RGB and extact two LSB's*/
  for(i = 0; i < pixelHeight * rowSize; i+=4)
  {
    unsigned char bytes[4];
    unsigned char out = 0;

    fread(&bytes, 1, 4, in);

    bytes[0] = (bytes[0] & 3) << 6;
    bytes[1] = (bytes[1] & 3) << 4;
    bytes[2] = (bytes[2] & 3) << 2;
    bytes[3] = bytes[3] & 3;

    out = bytes[0] | bytes[1] | bytes[2] | bytes[3];

    if(out == 0)
    {
      fclose(in);
      return 0;
    }
    printf("%c", out);
  }
  fclose(in);
  return 0;
}
