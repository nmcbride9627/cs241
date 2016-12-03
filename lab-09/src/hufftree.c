/**********************/
/* Nathaniel McBride	*/
/* December 6, 2016	  */
/* CS-241-002				  */
/**********************/

#include "hufftree.h"
#include <stdlib.h>
#include <stdbool.h>

struct HuffNode* createNode(unsigned char symbol, unsigned long frequency)
{
  struct HuffNode* newNode = malloc(sizeof(struct HuffNode));
  newNode->isLeaf = true;
  newNode->symbol = symbol;
  newNode->frequency = frequency;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct HuffNode* createMiniTree(struct HuffNode* left, struct HuffNode* right)
{
  struct HuffNode* newNode = createNode(0, (left->frequency + right->frequency));
  newNode->isLeaf = false;
  newNode->left = left;
  newNode->right = right;
  return newNode;
}
