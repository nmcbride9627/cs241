/**********************/
/* Nathaniel McBride	*/
/* December 6, 2016	  */
/* CS-241-002				  */
/**********************/

#ifndef HUFFTREE_H
#define HUFFTREE_H

#include <stdbool.h>

struct HuffNode
{
  unsigned char symbol;
  unsigned long frequency;
  struct HuffNode* left;
  struct HuffNode* right;
};

struct Code
{
  unsigned int code;
  unsigned int length;
};

struct HuffHeap
{
  unsigned long size;
  unsigned long capacity;
  struct HuffNode** array;
};

struct HuffNode* createNode(unsigned char symbol, unsigned long frequency);

struct HuffHeap* createHeap(unsigned long capacity);

struct HuffNode* createMiniTree(struct HuffNode* left, struct HuffNode* right);

struct Code* createCode(unsigned int code, unsigned int length);

bool isLeaf(struct HuffNode* root);

void swapNodes(struct HuffNode** nodeA, struct HuffNode** nodeB);

void insertNode(struct HuffHeap* heap, struct HuffNode* node);

struct HuffNode* removeNode(struct HuffHeap* heap);

void buildMinHeap(struct HuffHeap* heap);

void minHeapify(struct HuffHeap* heap, int i);

void printHeap(struct HuffHeap* heap);


#endif
