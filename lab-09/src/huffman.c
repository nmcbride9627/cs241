/**********************/
/* Nathaniel McBride	*/
/* December 6, 2016	  */
/* CS-241-002				  */
/**********************/

#include "huffman.h"
#include "hufftree.h"
#include <stdio.h>

#define MAX 256

int genFreqArrayEncode(FILE* fptr, unsigned long frequency[MAX])
{
  unsigned char c = fgetc(fptr);
  int totalNumChars = 0;
  while(!feof(fptr))
  {
    frequency[c]++;
    totalNumChars++;
    c = fgetc(fptr);
  }
  rewind(fptr);
  return totalNumChars;
}

int genFreqArrayDecode(FILE* fptr, unsigned long frequencyTable[MAX])
{
  unsigned int i;
  unsigned char numSymbols;
  unsigned char symbol;
  unsigned long frequency;
  unsigned long totalNumSymbols;
  fread(&numSymbols, sizeof(unsigned char), 1, fptr);
  for(i = 0; i < numSymbols; i++)
  {
    fread(&symbol, sizeof(unsigned char), 1, fptr);
    fread(&frequency, sizeof(unsigned long), 1, fptr);
    frequencyTable[symbol] = frequency;
  }
  fread(&totalNumSymbols, sizeof(unsigned long), 1, fptr);
  return totalNumSymbols;
}

struct HuffHeap* genPriorityQueue(unsigned long frequency[MAX],
  unsigned long capacity, unsigned char* numSymbols)
{
  unsigned int i = 0;
  struct HuffHeap* priorityQueue = createHeap(capacity);
  for(i = 0; i < MAX; i++)
  {
    if(frequency[i] != 0)
    {
      insertNode(priorityQueue, createNode(i, frequency[i]));
      (*numSymbols)++;
    }
  }
  return priorityQueue;
}

struct HuffNode* genHuffTree(struct HuffHeap* heap)
{
  while(heap->size > 1)
  {
    insertNode(heap, createMiniTree(removeNode(heap), removeNode(heap)));
  }
  return heap->array[0];
}

void genHuffCodes(struct HuffNode* root, struct Code* codeTable[MAX],
  unsigned int code, unsigned int iterator)
{
  if(root->left != NULL)
  {
    genHuffCodes(root->left, codeTable, code * 2, iterator + 1);
  }
  if(root->right != NULL)
  {
    genHuffCodes(root->right, codeTable,  (code * 2) + 1, iterator + 1);
  }
  if(isLeaf(root) == true)
  {
    codeTable[root->symbol] = createCode(code, iterator);
  }
}

void printCode(int code, int length)
{
  if(length > 0)
  {
    printCode(code / 2, length - 1);
  }
  printf("%d", code % 2);
}

void printArray(int array[], int size)
{
  int i;
  for(i = 0; i < size; i++)
  {
    printf("%d", array[i]);
  }
}

void printULArray(unsigned long array[], int size)
{
  int i;
  for(i = 0; i < size; i++)
  {
    printf("array[%d] = %lu ",i, array[i]);
  }
}

void printSymFreqCode(unsigned long frequency[MAX], struct Code* codeTable[MAX])
{
  int i;
  printf("Symbol Freq Code\n");
  for(i = 0; i < MAX; i++)
  {
    if(frequency[i] != 0)
    {
      if(i <= 32)
      {
        printf("=%d %lu ",i,frequency[i]);
        printCode(codeTable[i]->code, codeTable[i]->length -1);
        printf("\n");
      }
      else
      {
        printf("%c %lu ",i,frequency[i]);
        printCode(codeTable[i]->code, codeTable[i]->length -1);
        printf("\n");
      }
    }
  }
}

void printEverything(struct HuffNode* root, int array[], int itr)
{

  if(root->left != NULL)
  {
    array[itr] = 0;
    printEverything(root->left, array, itr + 1);
  }
  if(root->right != NULL)
  {
    array[itr] = 1;
    printEverything(root->right, array, itr + 1);
  }
  if(isLeaf(root) == true)
  {
    if(root->symbol < 33 || root->symbol > 126)
    {
      printf("=%d ", root->symbol);
    }
    else
    {
      printf("%c ", root->symbol);
    }
    printf("%lu ", root->frequency);
    printArray(array, itr);
    printf("\n");
  }
}



void printVals(unsigned long frequency[MAX])
{
  int i;
  printf("Symbol  Freq\n");
  for(i = 0; i < MAX; i++)
  {
    if(frequency[i] != 0)
    {
      if(i <= 32)
      {
        printf("=%d%8lu ",i,frequency[i]);
        printf("\n");
      }
      else
      {
        printf("%c%10lu ",i,frequency[i]);
        printf("\n");
      }
    }
  }
}

void printWrapper(struct HuffNode* root, bool newLineWrap, bool printL)
{
	if(root != NULL)
	{
		printWrapper(root->left, false, printL);
		if(printL)
		{
			if(root->left == NULL && root->right == NULL)
			{
				printf("%lu ", root->frequency);
			}
		}
		else
		{
			printf("%lu ", root->frequency);
		}
		printWrapper(root->right, false, printL);
	}
	if(newLineWrap)
	{
		printf("\n");
	}
}

void printTree(struct HuffNode* root)
{
	printWrapper(root, true, false);
}

void writeHeader(FILE* fptr, unsigned char numSymbols,
  unsigned long frequency[MAX], unsigned long totalNumSymbols)
{
  unsigned long i;
  fwrite(&numSymbols, sizeof(unsigned char), 1, fptr);
  for(i = 0; i < MAX; i++)
  {
    if(frequency[i] != 0)
    {
      fwrite(&i, sizeof(unsigned char), 1, fptr);
      fwrite(&frequency[i], sizeof(unsigned long), 1, fptr);
    }
  }
  fwrite(&totalNumSymbols, sizeof(unsigned long), 1, fptr);
}

void writePayload(FILE* in, FILE* out, struct Code* codeTable[MAX])
{
  unsigned char c;
  unsigned char output = 0;
  unsigned int tempCode = 0;
  int bitsStored = 0;
  while(!feof(in))
  {
    fread(&c, sizeof(unsigned char), 1, in);
    if(8 - bitsStored <= codeTable[c]->length)
    {
      output <<= codeTable[c]->length;
      output |= codeTable[c]->code;
      bitsStored += codeTable[c]->length;
    }
    else
    {
      output <<= (8 - bitsStored);
      tempCode = (codeTable[c]->code) >>
        (codeTable[c]->length - (8 - bitsStored));
      output |= tempCode;
      fwrite(&output, sizeof(unsigned char), 1, out);
      output = 0;
      tempCode = codeTable[c]->code <<
        (8 - (codeTable[c]->length - (8 - bitsStored)));
      tempCode >>= (8 - (codeTable[c]->length - (8 - bitsStored)));
      output |= tempCode;
      bitsStored = 8 - (8 - (codeTable[c]->length - (8 - bitsStored)));
    }
  }
  if(bitsStored != 0)
  {
    output <<= (8 - bitsStored);
    fwrite(&output, sizeof(unsigned char), 1, out);
  }
}

/**************************************************************/
/* Huffman encode a file.                                     */
/*     Also writes freq/code table to standard output         */
/* in -- File to encode.                                      */
/*       May be binary, so don't assume printable characters. */
/* out -- File where encoded data will be written.            */
/**************************************************************/
void encodeFile(FILE* in, FILE* out)
{
  unsigned char numberSymbols = 0;
  unsigned long totalNumSymbols = 0;
  unsigned long frequency[MAX] = {0};
  struct Code* codeTable[MAX] = {0};
  struct HuffHeap* priorityQueue;
  struct HuffNode* huffmanTree;

  totalNumSymbols = genFreqArrayEncode(in, frequency);
  priorityQueue = genPriorityQueue(frequency, totalNumSymbols, &numberSymbols);
  huffmanTree = genHuffTree(priorityQueue);
  genHuffCodes(huffmanTree, codeTable, 0, 0);
  printSymFreqCode(frequency, codeTable);
  writeHeader(out, numberSymbols, frequency, totalNumSymbols);
  writePayload(in, out, codeTable);
}

/***************************************************/
/* Decode a Huffman encoded file.                  */
/* in -- File to decode.                           */
/* out -- File where decoded data will be written. */
/***************************************************/
void decodeFile(FILE* in, FILE* out)
{
  /*
  unsigned long frequency[MAX] = {0};
  int array[MAX] = {0}, itr = 0;
  unsigned int totalNumChars = genFreqArrayDecode(in, frequency);
  struct HuffHeap* priorityQueue = genPriorityQueue(frequency, totalNumChars, numberSymbols);
  struct HuffNode* huffmanTree= genHuffTree(priorityQueue);*/
}
