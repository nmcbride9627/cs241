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
  bool isLeaf;
  unsigned char symbol;
  unsigned long frequency;
  struct HuffNode* left;
  struct HuffNode* right;
};

struct HuffNode* createNode(unsigned char symbol, unsigned long frequency);

struct HuffNode* createMiniTree(struct HuffNode* left, struct HuffNode* right);


#endif
