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

Bool LinkedListDelete(LinkedList* this, Node item) {
  uint64 counter = 0;
  Node* iterator = this->Head;
  while (counter < this->Lenght) {
    if(iterator->Value == item.Value) {
      iterator->Previous->Next = iterator->Next;
      iterator->Next->Previous = iterator->Previous;
      NodeFree(&iterator);
      return True;
    }
    iterator = iterator->Next;
    counter++;
  }
  return False;
}

void LinkedListInsert(LinkedList this, Node item, uint64 position);

void LinkedListAppendItem(LinkedList this, Node item);

void LinkedListReverseAppendItem(LinkedList this, Node item);

LinkedList LinkedListAppendLinkedList(LinkedList left, LinkedList right);

LinkedList LinkedListReverseAppendLinkedList(LinkedList left, LinkedList right);

LinkedList LinkedListSpan(LinkedList source, uint64 initial, uint64 final);

LinkedList LinkedListFree(LinkedList* this);

static uint64 connectNodes(Node* head, Node* tail) {
  if (head == NULL) {
    return 0;
  }

  uint64 counter = 1;
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
