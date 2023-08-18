#ifndef CMSTD_STACK_H
#define CMSTD_STACK_H

#include "../Node/Node.h"

struct Stack {
  Node* Top;
  uint64 Lenght;
};

typedef struct Stack Stack;

/* Returns a new Stack instance */
Stack* StackNew();

/* Removes the top from the stack */
Node* StackPop(Stack* this);

/* Add a new Node to the top of the stack*/
void StackPush(Stack* this, Node* node);

/* Free the stack pointer */
void StackFree(Stack* this);

#endif

