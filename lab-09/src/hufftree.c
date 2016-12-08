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

struct HuffNode* createMiniTree(struct HuffNode* left, struct HuffNode* right)
{
  struct HuffNode* newNode = malloc(sizeof(struct HuffNode));
  newNode->symbol = 0;
  newNode->frequency = left->frequency + right->frequency;
  newNode->left = left;
  newNode->right = right;
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

void insertNode(struct HuffHeap* heap, struct HuffNode* node)
{
  if(heap->size == heap->capacity)
  {
    printf("Error: Heap full\n");
  }
  else
  {
    int i = heap->size;
    heap->size++;
    heap->array[i] = node;

    while(i != 0 && heap->array[(i-1)/2]->frequency >= heap->array[i]->frequency)
    {
      if(heap->array[(i-1)/2]->frequency > heap->array[i]->frequency)
      {
        swapNodes(&heap->array[i], &heap->array[(i-1)/2]);
        i = (i-1)/2;
      }
      if(heap->array[(i-1)/2]->frequency == heap->array[i]->frequency)
      {
        if(heap->array[(i-1)/2]->right != NULL && heap->array[i]->right != NULL)
        {
          if(heap->array[(i-1)/2]->right->symbol < heap->array[i]->right->symbol)
          {
            swapNodes(&heap->array[i], &heap->array[(i-1)/2]);
            i = (i-1)/2;
          }
        }
        else if(heap->array[i]->right != NULL)
        {
          swapNodes(&heap->array[i], &heap->array[(i-1)/2]);
          i = (i-1)/2;
        }
      }
    }
  }
}

struct HuffNode* removeNode(struct HuffHeap* heap)
{
  struct HuffNode* temp;
  if(heap->size <= 0)
  {
    printf("Error: Heap empty\n");
  }
  if(heap->size == 1)
  {
    heap->size--;
    return heap->array[0];
  }
  temp = heap->array[0];
  heap->array[0] = heap->array[heap->size -1];
  heap->size--;
  minHeapify(heap, 0);
  return temp;
}

void buildMinHeap(struct HuffHeap* heap)
{
  int i;
  int heapSize = heap->size - 1;
  for(i = (heapSize-1)/2; i >= 0; i--)
  {
    minHeapify(heap, i);
  }
}


void printHeap(struct HuffHeap* heap)
{
  int i;
  for(i = 0; i < heap->size; i++)
  {
    printf("%c: %lu\n", heap->array[i]->symbol, heap->array[i]->frequency);
  }
  printf("\n");
}

void minHeapify(struct HuffHeap* heap, int i)
{
  int smallest = i;
  int left = 2*i+1;
  int right = 2*i+2;

  if(left < heap->size &&
    heap->array[left]->frequency < heap->array[smallest]->frequency)
  {
    smallest = left;
  }
  if(right < heap->size &&
    heap->array[right]->frequency < heap->array[smallest]->frequency)
  {
    smallest = right;
  }
  if(smallest != i)
  {
    swapNodes(&heap->array[smallest], &heap->array[i]);
    minHeapify(heap, smallest);
  }
}
