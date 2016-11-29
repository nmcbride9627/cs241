/**********************/
/* Nathaniel McBride	*/
/* December 6, 2016	  */
/* CS-241-002				  */
/**********************/

#include "huffman.h"
#include <stdio.h>

/**************************************************************/
/* Huffman encode a file.                                     */
/*     Also writes freq/code table to standard output         */
/* in -- File to encode.                                      */
/*       May be binary, so don't assume printable characters. */
/* out -- File where encoded data will be written.            */
/**************************************************************/
void encodeFile(FILE* in, FILE* out)
{

}

/***************************************************/
/* Decode a Huffman encoded file.                  */
/* in -- File to decode.                           */
/* out -- File where decoded data will be written. */
/***************************************************/
void decodeFile(FILE* in, FILE* out)
{

}

void genFreqArray(FILE* fptr, int freqency[256])
{
  int c;
  while((c = fgetc(fptr))!= EOF)
  {
    freqency[c]++;
  }
  rewind(fptr);
}

void printFreq(int freqency[256])
{
  int i;
  for(i=0;i<256;i++)
  {
    if(freqency[i] != 0)
    {
      printf("%5c%10d\n",i,freqency[i]);
    }
  }
}
