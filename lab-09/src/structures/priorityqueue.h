/**********************/
/* Nathaniel McBride	*/
/* December 6, 2016	  */
/* CS-241-002				  */
/**********************/

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "huffmantree.h"
#include <stdbool.h>

bool isEmpty();

bool isFull();

int sizeofqueue();

void insertNode(struct HuffNode* node);

struct HuffNode* peek();

struct HuffNode* dequeueNode();

#endif
