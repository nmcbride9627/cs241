/**********************/
/* Nathaniel McBride	*/
/* December 6, 2016	  */
/* CS-241-002				  */
/**********************/
#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

struct HuffNode
{
  bool isLeaf;
  unsigned char symbol;
  unsigned long frequency;
  struct HuffNode* left;
  struct HuffNode* right;
};

struct HuffNode* createHuffNode(unsigned char symbol, unsigned long frequency);

void freeTree(struct HuffNode* root);

#endif
