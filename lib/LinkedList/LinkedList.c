#include "LinkedList.h"

/* Connects the new Nodes and returns the amount of items connected */
static uint64 connectNodes(Node* head, Node* tail);

LinkedList* LinkedListNew(Node head, Node tail) {
  LinkedList* result = (LinkedList*)malloc(sizeof(LinkedList));
  result->Head = NodeClone(head);
  result->Tail = NodeClone(tail);
  result->Lenght = connectNodes(result->Head, &tail);
  return result;
}

Result GetNode(LinkedList this, uint64 index) {
  if (index > this.Lenght) {
    String* errorMessage = StringNew("The index is out of range");
    Result result = ResultError(&errorMessage);
    return result;
  }

  if (index == 0) {
    Result result = ResultOk(this.Head);
    return result;
  }

  if (index == this.Lenght) {
    Result result = ResultOk(this.Tail);
    return result;
  }

  Node* wantedNode = this.Head;
  for (uint64 i = 0; i < this.Lenght && wantedNode != this.Tail; i++) {
    if (i == index) {
      Result result = ResultOk(wantedNode);
      return result;
    }
    wantedNode = wantedNode->Next;
  }

  // This should never be executed
  String* errorMessage = StringNew("Something unexpected happened");
  Result result = ResultError(&errorMessage);
  return result;
}

Result LinkedListRemove(LinkedList* this, uint64 index) {
  Result getNodeResult = GetNode(*this, index);
  if (!getNodeResult.Ok) {
    return getNodeResult;
  }

  Node* wantedNode = (Node*)getNodeResult.Value;
  wantedNode->Next->Previous = wantedNode->Previous;
  wantedNode->Previous->Next = wantedNode->Next;
  NodeFree(&wantedNode);

  return ResultOk(NULL);
}

Result LinkedListInsert(LinkedList* this, Node* item, uint64 index) {
  Result getNodeResult = GetNode(*this, index);
  if (!getNodeResult.Ok) {
    return getNodeResult;
  }

  Node* wantedNode = (Node*)getNodeResult.Value;
  item->Previous = wantedNode->Previous;
  item->Next = wantedNode;
  wantedNode->Next->Previous = item;

  return ResultOk(NULL);
}

Result LinkedListSpan(LinkedList source, uint64 head, uint64 tail) {
  Result headResult = GetNode(source, head);
  if (!headResult.Ok) {
    return headResult;
  }

  Result tailResult = GetNode(source, tail);
  if (!headResult.Ok) {
    return headResult;
  }

  LinkedList* newList
      = LinkedListNew(*((Node*)headResult.Value), *((Node*)tailResult.Value));
  Result result = ResultOk(newList);
  return result;
}

void LinkedListFree(LinkedList* this) {
  Node* currentNode = this->Head;
  while (currentNode != NULL) {
    Node* temporalNode = currentNode->Next;
    NodeFree(&currentNode);
    currentNode = temporalNode;
  }
  free(this);
}

static uint64 connectNodes(Node* head, Node* tail) {
  if (head == NULL) {
    return 0;
  }

  uint64 counter = 0;
  Node* beginning = head;

  while (head != tail && head->Next != NULL) {
    Node* originalNext = head->Next;

    Node* nextClone = NodeClone(*head->Next);
    NodeChangeNext(head, nextClone);
    NodeChangePrevious(nextClone, head);

    head = originalNext;
    counter++;
  }

  head = beginning;
  return counter;
}
