#include "Node.h"

static void cloneValue(void* source, void* destination, uint64 size);
static Node* newNode(void* value, uint64 dataSize, Node* next, Node* previous);
static Bool nodeValidateNext(Node* next, uint64 dataSize);
static Bool nodeValidatePrevious(Node* previous, uint64 dataSize);

Node* NodeNew(void* value, uint64 DataSize, Node* next, Node* previous) {
  void* allocatedValue = malloc(DataSize);
  cloneValue(allocatedValue, value, DataSize);
  return newNode(allocatedValue, DataSize, next, previous);
}

Node* NodeClone(Node source) {
  void* allocatedValue = malloc(source.DataSize);
  cloneValue(allocatedValue, source.Value, source.DataSize);
  return newNode(allocatedValue, source.DataSize, source.Next, source.Previous);
}

void NodeChangeNext(Node* this, Node* next) {
  this->Next = next;
}

void NodeChangePrevious(Node* this, Node* previous) {
  this->Previous = previous;
}

void NodeFree(Node** this) {
  free((*this)->Value);
  (*this)->Value = NULL;
  free(*this);
  *this = NULL;
}

// TODO: Move to a generic function
static void cloneValue(void* source, void* destination, uint64 size) {
  Byte* destinationBeginning = (Byte*)destination;
  Byte* sourceBeginning = (Byte*)source;

  while ((*destinationBeginning++ = *sourceBeginning++) && size > 0) {
    size--;
  }
}

Node* newNode(void* value, uint64 dataSize, Node* next, Node* previous) {
  if (next != NULL && nodeValidateNext(next, dataSize) == False) {
    return NULL;
  }

  if (previous != NULL && nodeValidatePrevious(previous, dataSize) == False) {
    return NULL;
  }

  Node* result = (Node*)malloc(sizeof(Node));
  result->Value = value;
  result->DataSize = dataSize;
  NodeChangeNext(result, next);
  NodeChangePrevious(result, previous);
  return result;
}

static Bool nodeValidateNext(Node* next, uint64 dataSize) {
  if (dataSize != next->DataSize) {
    return False;
  }
  return True;
}

static Bool nodeValidatePrevious(Node* previous, uint64 dataSize) {
  if (dataSize != previous->DataSize) {
    return False;
  }
  return True;
}
