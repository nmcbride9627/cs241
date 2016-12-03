/**********************/
/* Nathaniel McBride	*/
/* December 6, 2016	  */
/* CS-241-002				  */
/**********************/

#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode
{
  int symbol;
  int weight;
  struct QueueNode* next;
};

struct QueueNode* createQueueNode(int symbol, int weight);

struct QueueNode* enqueueNode(struct QueueNode* head, struct QueueNode* newNode);

struct QueueNode* insertSorted(struct QueueNode* head, int weight);

struct QueueNode* dequeueNode(struct QueueNode* head);

void printQueue(struct QueueNode* head);

#endif
