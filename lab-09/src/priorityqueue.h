/**********************/
/* Nathaniel McBride	*/
/* December 6, 2016	  */
/* CS-241-002				  */
/**********************/

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "hufftree.h"
#include <stdbool.h>

#define MAX 256

struct PriorityQueue
{
  int elementCount;
  struct HuffNode* queueArray[MAX];
};

bool isEmpty();

bool isFull();

int sizeofqueue();

void insertNode(struct PriorityQueue* queue, struct HuffNode* node);

struct HuffNode* peek();

struct HuffNode* dequeueNode();

#endif
