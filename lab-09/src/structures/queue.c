/**********************/
/* Nathaniel McBride	*/
/* December 6, 2016	  */
/* CS-241-002				  */
/**********************/

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct QueueNode* createQueueNode(int symbol, int weight)
{
  struct QueueNode* newNode = malloc(sizeof(struct QueueNode));
  newNode->symbol = symbol;
  newNode->weight = weight;
  newNode->next = NULL;
  return newNode;
}

struct QueueNode* enqueueNode(struct QueueNode* head, struct QueueNode* newNode)
{
  struct QueueNode* current = head;

  if(head == NULL)
  {
    newNode->next = head;
    head = newNode;
  }
  else
  {
    while(current->next != NULL)
    {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode->next;
  }
  return head;
}

struct QueueNode* dequeueNode(struct QueueNode* head)
{
  struct QueueNode* node = head;
  head = head->next;
  return node;
}

void printQueue(struct QueueNode* head)
{
  struct QueueNode* current = head;
  while(current != NULL)
  {
    printf("symbol = %d, weight = %d\n", current->symbol, current->weight);
    current = current-> next;
  }
  printf("\n");
}
