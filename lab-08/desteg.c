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

  int fileSize;
  int pixelWidth;
  int pixelHeight;
  int pixelDataSize;
  int rowSize;
  int rowPadding;

  int i, j;

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

  fileSize = getIntFromArray(&header[2]);
  pixelWidth = getIntFromArray(&header[18]);
  pixelHeight = getIntFromArray(&header[22]);
  pixelDataSize = getIntFromArray(&header[34]);

  /* compute row padding */
  rowSize = pixelWidth*3;
  rowPadding = (4 - (rowSize % 4)) % 4;
  rowSize += rowPadding;

  printf("pixelWidth  = %d pixels\n", pixelWidth);
  printf("pixelHeight = %d pixels\n", pixelHeight);
  printf("rowPadding  = %d bytes\n", rowPadding);
  printf("rowSize     = %d bytes\n", rowSize);
  printf("pixelDataSize = %d bytes\n", pixelDataSize);
  printf("fileSize = %d bytes\n", fileSize);

  /* Read RGB data from original, copy without red */
  for(i = 0; i < pixelHeight; ++i)
  {
    for(j = 0; j < pixelWidth; ++j)
    {
      unsigned char bytes[3];
      unsigned char temp[3] = {0};
      unsigned char out = 0;

      /* color order is BGR */
      fread(&bytes, 1, 4, in);

      temp[0] = (bytes[0] & 3) << 6;
      temp[1] = (bytes[1] & 3) << 4;
      temp[2] = (bytes[2] & 3) << 2;
      temp[3] = bytes[3] & 3;

      out = temp[0] | temp[1] | temp[2] | temp[3];
      printf("%c", out);
      if(out == '\n')
      {
        break;
      }

    }
    /* handle end of row padding */
    fseek(in, rowPadding, SEEK_CUR);
  }
  fclose(in);
  return 0;
}
