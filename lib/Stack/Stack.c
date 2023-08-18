#include "Stack.h"

Stack* StackNew() {
  Stack* result = (Stack*)malloc(sizeof(Stack));
  result->Lenght = 0;
  result->Top = NULL;
  return result;
}

Node* StackPop(Stack* this) {
  Node* previous = this->Top->Previous;
  this->Top = previous;
  return previous;
}

void StackPush(Stack* this, Node* node) {
  Node* previousTop = this->Top;
  this->Top = NodeClone(*node);
  this->Top->Previous = previousTop;
}

void StackFree(Stack* this) {
  free(this);
  this = NULL;
}
