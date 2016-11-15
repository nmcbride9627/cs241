/**********************/
/* Nathaniel McBride  */
/* November 14, 2016  */
/* CS-241-002         */
/**********************/

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Alloc a new node with given data. */
struct ListNode* createNode(int data)
{
  struct ListNode* newNode = malloc(sizeof(struct ListNode));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

/* Insert data at appropriate place in a sorted list, return new list head. */
struct ListNode* insertSorted(struct ListNode* head, int data)
{
  struct ListNode* newNode = createNode(data);
  struct ListNode* current = head;

  if(head == NULL || head->data >= newNode->data)
  {
    newNode->next = head;
    head = newNode;
  }
  else
  {
    while(current->next != NULL &&
      current->next->data < newNode->data)
    {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
  return head;
}

/* Remove data from list pointed to by headRef, changing head if necessary.
 * Make no assumptions as to whether the list is sorted.
 * Memory for removed node should be freed.
 * Return 1 if data was present, 0 if not found. */
int removeItem(struct ListNode** headRef, int data)
{
  struct ListNode* previous = NULL;
  struct ListNode* current = *headRef;
  bool removedData = false;

  if(previous == NULL && current->data == data)
  {
    *headRef = current->next;
    free(current);
    removedData = true;
  }
  else
  {
    while(current != NULL)
    {
      if(current->data == data)
      {
        previous->next = current->next;
        free(current);
        removedData = true;
      }
      else
      {
        previous = current;
        current = current->next;
      }
    }
  }
  return removedData;
}

/* Insert data at head of list, return new list head. */
struct ListNode* pushStack(struct ListNode* head, int data)
{
  struct ListNode* newHead = createNode(data);
  newHead->next = head;
  return newHead;
}

/* Remove and return data from head of non-empty list, changing head.
 * Memory for removed node should be freed. */
int popStack(struct ListNode** headRef)
{
  int data;
  struct ListNode* node = *headRef;
  data = node->data;
  (*headRef) = node->next;
  free(node);
  return data;
}

/* Return length of the list. */
int listLength(struct ListNode* head)
{
  int count = 0;
  struct ListNode* current = head;
  while (current != NULL)
  {
    count++;
    current = current->next;
  }
  return count;
}

/* Print list data on single line, separated with spaces and ending
 * with newline. */
void printList(struct ListNode* head)
{
  struct ListNode* current = head;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

/* Free memory used by the list. */
void freeList(struct ListNode* head)
{
  if(head == NULL)
  {
    return;
  }
  freeList(head->next);
  free(head);
}

/* Reverse order of elements in the list */
void reverseList(struct ListNode** headRef)
{
  /*TODO*/
}
