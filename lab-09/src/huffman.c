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

void enqueueNode(struct HuffNode* queue[MAX], int* elementCount, struct HuffNode* node)
{
  int i = 0;

  if((*elementCount) != MAX)
  {
    if((*elementCount) == 0)
    {
      queue[0] = node;
    }
    else
    {
      for(i = (*elementCount) - 1; i >= 0; i--)
      {
        if(node->frequency > queue[i]->frequency)
        {
          queue[i+1] = queue[i];
        }
        else if(node->frequency == queue[i]->frequency)
        {
          if(node->right != NULL && queue[i]->right != NULL)
          {
            if(node->right->frequency < queue[i]->right->frequency)
            {
              queue[i+1] = queue[i];
            }
            else
            {
              break;
            }
          }
          else if(node->right != NULL)
          {
            queue[i+1] = queue[i];
          }
          else
          {
            break;
          }
        }
        else
        {
          break;
        }
      }
      queue[i+1] = node;
    }
    (*elementCount)++;
  }
}

struct HuffNode* dequeueNode(struct HuffNode* queue[MAX], int* elementCount)
{
  return queue[--(*elementCount)];
}

void genPriorityQueue(struct HuffNode* queue[MAX], int* elementCount, unsigned long frequency[MAX])
{
  int i;
  for(i = 0; i < MAX; i++)
  {
    if(frequency[i] != 0)
    {
      struct HuffNode* newNode = createNode(i, frequency[i]);
      enqueueNode(queue, elementCount, newNode);
    }
  }
}

struct HuffNode* genHuffTree(struct HuffNode* queue[MAX], int* elementCount)
{
  while((*elementCount) > 1)
  {
    /* This take two nodes out of the queue, places them in a mini tree,
     * then puts the root back into the queue */
    enqueueNode(queue, elementCount,
      createMiniTree(dequeueNode(queue, elementCount),
        dequeueNode(queue, elementCount)));
  }
  return queue[0];
}

void genCodeTable(int codeTable[], struct HuffNode* node, int code)
{
  if(node->isLeaf == true)
  {
    codeTable[node->symbol] = code;
  }
  else
  {
    genCodeTable(codeTable, node->left, code * 2);
    genCodeTable(codeTable, node->right, (code * 2) + 1);
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

void printVals(unsigned long frequency[MAX], int codeTable[MAX])
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
        printCode(codeTable[i]);
        printf("\n");
      }
      else
      {
        printf("%c%10lu ",i,frequency[i]);
        printCode(codeTable[i]);
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
  int totalNumChars = 0;
  int elementCount = 0;
  unsigned long frequency[MAX] = {0};
  int codeTable[MAX] = {0};
  struct HuffNode* queue[MAX] = {NULL};
  struct HuffNode* tree;

  totalNumChars = genFreqArray(in, frequency);
  genPriorityQueue(queue, &elementCount, frequency);

  tree = genHuffTree(queue, &elementCount);
  genCodeTable(codeTable, tree, 0);

  printVals(frequency, codeTable);
  printf("Total chars = %d\n", totalNumChars);\
}

/***************************************************/
/* Decode a Huffman encoded file.                  */
/* in -- File to decode.                           */
/* out -- File where decoded data will be written. */
/***************************************************/
void decodeFile(FILE* in, FILE* out)
{

}
