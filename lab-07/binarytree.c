/**********************/
/* Nathaniel McBride	*/
/* November 14, 2016	*/
/* CS-241-002				 */
/**********************/

#include "binarytree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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
	if(root == NULL)
	{
		return createNode(data);
	}
	if(data < root->data)
	{
		root->left = insertBST(root->left, data);
	}
	else if(data > root->data)
	{
		root->right = insertBST(root->right, data);
	}
	return root;
}

/* Remove data from BST pointed to by rootRef, changing root if necessary.
 * For simplicity's sake, always choose node's in-order
 *	 predecessor in the two-child case.
 * Memory for removed node should be freed.
 * Return 1 if data was present, 0 if not found. */
int removeBST(struct TreeNode** rootRef, int data)
{
	/*TODO*/
	return 0;
}

/* Return maximum value in non-empty binary search tree. */
int maxValueBST(struct TreeNode* root)
{
	int maxValue = INT_MIN;
	int maxValueL, maxValueR;
	if(root != NULL)
	{
		maxValue = root->data;
		maxValueL = maxValueBST(root->left);
		maxValueR = maxValueBST(root->right);
		if(maxValueL > maxValue)
		{
			maxValue = maxValueL;
		}
		if(maxValueR > maxValue)
		{
			maxValue = maxValueR;
		}
	}
	return maxValue;
}

/* Return minimum value in non-empty binary search tree. */
int minValueBST(struct TreeNode* root)
{
	int minValue = INT_MAX;
	int minValueL, minValueR;
	if(root != NULL)
	{
		minValue = root->data;
		minValueL = minValueBST(root->left);
		minValueR = minValueBST(root->right);
		if(minValueL < minValue)
		{
			minValue = minValueL;
		}
		if(minValueR < minValue)
		{
			minValue = minValueR;
		}
	}
	return minValue;
}

/* Return maximum depth of tree. Empty tree has depth 0. */
int maxDepth(struct TreeNode* root)
{
	int maxDepthL, maxDepthR;
	if(root != NULL)
	{
		maxDepthL = maxDepth(root->left);
		maxDepthR = maxDepth(root->right);
		if(maxDepthL > maxDepthR)
		{
			return ++maxDepthL;
		}
		else
		{
			return ++maxDepthR;
		}
	}
	else
	{
		return 0;
	}
}

/* A tree is balanced if both subtrees are balanced and
 * the difference in height between the subtrees is no more than 1.
 * Return 1 if tree is balanced, 0 if not. */
int isBalanced(struct TreeNode* root)
{
	int depthL, depthR, diff;
	if(root != NULL)
	{
		depthL = maxDepth(root->left);
		depthR = maxDepth(root->right);
		diff = abs(depthL - depthR);
		if(diff <= 1 && isBalanced(root->left) && isBalanced(root->right))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 1;
	}
}

/* Return 1 if tree is a binary search tree, 0 if not. */
int isBST(struct TreeNode* root)
{
	/*TODO*/
	if(root != NULL)
	{
		if(root->left != NULL && maxValueBST(root->left) > root->data)
		{
			return 0;
		}
		if(root->right != NULL && minValueBST(root->right) < root->data)
		{
			return 0;
		}
		if(!isBST(root->left) || !isBST(root->right))
		{
			return 0;
		}
	}
	return 1;
}

/* This function is wrapped by printTree and printLeaves
 * to print the whole tree or just the leaves
 * specified by printL(printLeaves) parameter
 * with a newline character before last return
 * while retaining the use of recursion */
void printWrapper(struct TreeNode* root, bool newLineWrap, bool printL)
{
	if(root != NULL)
	{
		printWrapper(root->left, false, printL);
		if(printL)
		{
			if(root->left == NULL && root->right == NULL)
			{
				printf("%d ", root->data);
			}
		}
		else
		{
			printf("%d ", root->data);
		}
		printWrapper(root->right, false, printL);
	}
	if(newLineWrap)
	{
		printf("\n");
	}
}
/* Print data for inorder (left, root, right)
 * tree traversal on single line,
 * separated with spaces, ending with newline. */
void printTree(struct TreeNode* root)
{
	printWrapper(root, true, false);
}

/* Print data for leaves on single line,
 * separated with spaces, ending with newline.*/
void printLeaves(struct TreeNode* root)
{
	printWrapper(root, true, true);
}

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
