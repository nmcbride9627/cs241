/**********************/
/* Nathaniel McBride	*/
/* December 6, 2016	  */
/* CS-241-002				  */
/**********************/

#include "hufftree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 256

struct HuffNode* peek(struct HuffNode* queue[MAX], int* elementCount)
{
  return queue[(*elementCount) - 1];
}

struct HuffNode* dequeueNode(struct HuffNode* queue[MAX], int* elementCount)
{
  return queue[--(*elementCount)];
}
