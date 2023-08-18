#ifndef CMSTD_LINKEDLIST_H
#define CMSTD_LINKEDLIST_H

#include "../Node/Node.h"
#include "../PrimitiveTypes/PrimitiveTypes.h"
#include "../Result/Result.h"

struct LinkedList{
  Node* Head;
  Node* Tail;
  uint64 Lenght;
};

typedef struct LinkedList LinkedList;

/* Create a new LinkedList struct */
LinkedList* LinkedListNew(Node head, Node tail);

/* Returns a node at a specific index */
Result GetNode(LinkedList this, uint64 index);

/* Remove the item in the specified index from the LinkedList. */
Result LinkedListRemove(LinkedList* this, uint64 index);

/* Inserts a new item in the specified index. */
Result LinkedListInsert(LinkedList* this, Node* item, uint64 index);

/* Returns a new LinkedList struct containing a subset of items. */
Result LinkedListSpan(LinkedList source, uint64 head, uint64 tail);

/* Deallocates the LinkedList memory. */
void LinkedListFree(LinkedList* this);

#endif
