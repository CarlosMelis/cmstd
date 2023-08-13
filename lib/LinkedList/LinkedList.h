#ifndef CMSTD_LINKEDLIST_H
#define CMSTD_LINKEDLIST_H

#include "../Node/Node.h"
#include "../PrimitiveTypes/PrimitiveTypes.h"

typedef struct LinkedList {
  Node* Head;
  Node* Tail;
  uint64 Lenght;
} LinkedList;

/* Create a new LinkedList struct */
LinkedList* LinkedListNew(Node head, Node tail);

/* Deletes an item from the LinkedList. */
Bool LinkedListDelete(LinkedList* this, Node item);

/* Inserts a new item in the specified position. */
void LinkedListInsert(LinkedList this, Node item, uint64 position);

/* Appends the item at the tail of the LinkedList. */
void LinkedListAppendItem(LinkedList this, Node item);

/* Appends the item at the start of the LinkedList. */
void LinkedListReverseAppendItem(LinkedList this, Node item);

/* Appends the LinkedList struct items at the end of the LinkedList. */
LinkedList LinkedListAppendLinkedList(LinkedList left, LinkedList right);

/* Appends the LinkedList struct items at the start of the LinkedList. */
LinkedList LinkedListReverseAppendLinkedList(LinkedList left, LinkedList right);

/* Returns a new LinkedList struct containing a subset of items. */
LinkedList LinkedListSpan(LinkedList source, uint64 initial, uint64 final);

/* Deallocates the LinkedList memory. */
LinkedList LinkedListFree(LinkedList* this);

#endif
