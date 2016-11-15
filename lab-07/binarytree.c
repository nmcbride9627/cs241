/**********************/
/* Nathaniel McBride  */
/* November 14, 2016  */
/* CS-241-002         */
/**********************/

#include "binarytree.h"
#include <stdio.h>
#include <stdlib.h>

/* Alloc a new node with given data. */
struct TreeNode* createNode(int data)
{
  struct TreeNode* newNode = malloc(sizeof(struct TreeNode));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

/* Insert data at appropriate place in BST, return new tree root. */
struct TreeNode* insertBST(struct TreeNode* root, int data)
{
  if(data < root->data)
  {
    insertBST(root->left, data);
  }
}

/* Remove data from BST pointed to by rootRef, changing root if necessary.
 * For simplicity's sake, always choose node's in-order
 *   predecessor in the two-child case.
 * Memory for removed node should be freed.
 * Return 1 if data was present, 0 if not found. */
int removeBST(struct TreeNode** rootRef, int data);

/* Return maximum value in non-empty binary search tree. */
int maxValueBST(struct TreeNode* root);

/* Return maximum depth of tree. Empty tree has depth 0. */
int maxDepth(struct TreeNode* root);

/* A tree is balanced if both subtrees are balanced and
 * the difference in height between the subtrees is no more than 1.
 * Return 1 if tree is balanced, 0 if not. */
int isBalanced(struct TreeNode* root);

/* Return 1 if tree is a binary search tree, 0 if not. */
int isBST(struct TreeNode* root);

/* Print data for inorder (left, root, right)
 * tree traversal on single line,
 * separated with spaces, ending with newline. */
void printTree(struct TreeNode* root)
{
  if(root == NULL)
  {
    return;
  }
  printTree(root->left);
  printf("%d ", root->data);
  printTree(root->right);
}

/* Print data for leaves on single line,
 * separated with spaces, ending with newline.*/
void printLeaves(struct TreeNode* root);

/* Free memory used by the tree. */
void freeTree(struct TreeNode* root)
{
  if(root == NULL)
  {
    return;
  }
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}
