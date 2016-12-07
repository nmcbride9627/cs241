/**********************/
/* Nathaniel McBride	*/
/* December 6, 2016	  */
/* CS-241-002				  */
/**********************/

#include "huffman.h"
#include "hufftree.h"
#include <stdio.h>

#define MAX 256

int genFreqArray(FILE* fptr, unsigned long frequency[MAX])
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

struct HuffHeap* genPriorityQueue(unsigned long frequency[MAX], int capacity)
{
  int i, j = 0;
  struct HuffHeap* priorityQueue = createHeap(capacity);
  for(i = 0; i < MAX; i++)
  {
    if(frequency[i] != 0 && j < capacity)
    {
      priorityQueue->array[j] = createNode(i, frequency[i]);
      priorityQueue->size++;
      j++;
      buildMinHeap(priorityQueue);
    }
  }
  return priorityQueue;
}

void printArray(int array[], int size)
{
  int i;
  for(i = 0; i < size; i++)
  {
    printf("%d", array[i]);
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

void printCode(int num)
{
  if(num > 0)
  {
    printCode(num / 2);
  }
  if(num)
  {
    printf("%d", num % 2);
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

/**************************************************************/
/* Huffman encode a file.                                     */
/*     Also writes freq/code table to standard output         */
/* in -- File to encode.                                      */
/*       May be binary, so don't assume printable characters. */
/* out -- File where encoded data will be written.            */
/**************************************************************/
void encodeFile(FILE* in, FILE* out)
{
  unsigned long frequency[MAX] = {0};
  unsigned int totalNumChars = genFreqArray(in, frequency);
  struct HuffHeap* priorityQueue = genPriorityQueue(frequency, totalNumChars);
  printHeap(priorityQueue);
}

/***************************************************/
/* Decode a Huffman encoded file.                  */
/* in -- File to decode.                           */
/* out -- File where decoded data will be written. */
/***************************************************/
void decodeFile(FILE* in, FILE* out)
{

}
