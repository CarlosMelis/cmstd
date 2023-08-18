#ifndef CMSTD_NODE_H
#define CMSTD_NODE_H

#include <stdlib.h>
#include "../Bool/Bool.h"
#include "../PrimitiveTypes/PrimitiveTypes.h"

/* Establishes a collection relation between different values. */
struct Node {
  void* Value;
  uint64 DataSize;
  struct Node* Next;
  struct Node* Previous;
};

typedef struct Node Node;

/* Creates a new Node */
Node* NodeNew(void* value, uint64 DataSize, Node* next, Node* previous);

/* Returns a clone of the source Node struct */
Node* NodeClone(Node source);

/* Makes the Node struct next member point to passed Node struct pointer */
void NodeChangeNext(Node* this, Node* next);

/* Makes the Node struct previous member point to passed Node struct pointer */
void NodeChangePrevious(Node* this, Node* previous);

/* Deallocates the value and makes the members point to null */
void NodeFree(Node** this);

#endif
