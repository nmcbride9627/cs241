/**********************/
/* Nathaniel McBride	*/
/* December 6, 2016	  */
/* CS-241-002				  */
/**********************/

#include "hufftree.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct HuffNode* createNode(unsigned char symbol, unsigned long frequency)
{
  struct HuffNode* newNode = malloc(sizeof(struct HuffNode));
  newNode->symbol = symbol;
  newNode->frequency = frequency;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct HuffHeap* createHeap(unsigned long capacity)
{
  struct HuffHeap* heap = malloc(sizeof(struct HuffHeap));
  heap->size = 0;
  heap->capacity = capacity;
  heap->array = malloc(capacity * sizeof(struct HuffNode*));
  return heap;
}

bool isLeaf(struct HuffNode* root)
{
  return root->left == NULL && root->right == NULL;
}

void swapNodes(struct HuffNode** nodeA, struct HuffNode** nodeB)
{
  struct HuffNode* temp = *nodeA;
  *nodeA = *nodeB;
  *nodeB = temp;
}

void buildMinHeap(struct HuffHeap* heap)
{
  int i;
  int heapSize = heap->size - 1;
  for(i = heapSize/2; i > 0; i--)
  {
    minHeapify(heap, i);
  }
}

void minHeapify(struct HuffHeap* heap, int i)
{
  int smallest = i;
  int left = 2*i+1;
  int right = 2*i+2;
  if(right <= heap->size && heap->array[right] < heap->array[i])
  {
    smallest = right;
  }
  if(left <= heap->size && heap->array[left] < heap->array[smallest])
  {
    smallest = left;
  }
  if(smallest != i)
  {
    swapNodes(&heap->array[i], &heap->array[smallest]);
    minHeapify(heap, smallest);
  }
}

void printHeap(struct HuffHeap* heap)
{
  int i;
  for(i = 0; i < heap->size; i++)
  {
    printf("%c: %lu\n", heap->array[i]->symbol, heap->array[i]->frequency);
  }
}
