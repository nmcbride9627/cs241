/**********************/
/* Nathaniel McBride	*/
/* December 6, 2016	  */
/* CS-241-002				  */
/**********************/

#include "huffmantree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 256


struct HuffNode* queue[MAX];
int elementCount = 0;

bool isEmpty()
{
  return elementCount == 0;
}
bool isFull()
{
  return elementCount == MAX;
}

int sizeofqueue()
{
  return elementCount;
}

void insertNode(struct HuffNode* node)
{
  int i = 0;

  if(!isFull())
  {
    if(elementCount == 0)
    {
      queue[0] = node;
    }
    else
    {
      for(i = elementCount - 1; i >= 0; i--)
      {
        if(node->frequency > queue[i]->frequency)
        {
          queue[i+1] = queue[i];
          break;
        }
      }
      queue[i] = node;
    }
    elementCount++;
  }
}

struct HuffNode* peek()
{
  return queue[elementCount - 1];
}

struct HuffNode* dequeueNode()
{
  return queue[--elementCount];
}
