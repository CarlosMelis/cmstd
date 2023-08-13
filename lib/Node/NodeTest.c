#include "../Macros/Macros.h"
#include "../String/String.h"
#include "Node.h"

void NodeNewTest(void);
void NodeCloneTest(void);
void NodeChangeNextTest(void);
void NodeChangePreviousTest(void);
void NodeFreeTest(void);

int main() {
  NodeNewTest();
  NodeCloneTest();
  NodeChangeNextTest();
  NodeChangePreviousTest();
  NodeFreeTest();
}

void NodeNewTest(void) {
  // Arrange
  String* string = StringNew("Hello");

  // Act
  Node* NodeA = NodeNew(string, sizeof(String), NULL, NULL);

  // Assert
  Assert(StringEqual(*(String*)NodeA->Value, *string),
         "The value of the node is not the same");
  Assert(NodeA->Next == NULL, "Next pointer should be NULL");
  Assert(NodeA->Previous == NULL, "Previous pointer should be NULL");
  LogSuccess();
}

void NodeCloneTest(void) {
  // Arrange
  String* string = StringNew("Hello");
  Node* NodeA = NodeNew(string, sizeof(String), NULL, NULL);

  // Act
  Node* NodeB = NodeClone(*NodeA);

  // Assert
  Assert(NodeA != NodeB, "The nodes are the same");
  Assert(NodeA->Next == NodeB->Next, "Next pointer is not the expected");
  Assert(NodeA->Previous == NodeB->Previous, "Previous pointer is not the expected");
  Assert((String*)NodeA->Value != (String*)NodeB->Value,
         "The values shouldn't be pointing to the same memory address");
  LogSuccess();
}

void NodeChangeNextTest(void) {
  // Arrange
  Node* NodeA = NodeNew(StringNew("Hello"), sizeof(String), NULL, NULL);
  Node* NodeB = NodeNew(StringNew("to"), sizeof(String), NULL, NodeA);

  // Act
  NodeChangeNext(NodeA, NodeB);

  // Assert
  Assert(NodeA->Next == NodeB, "The next pointer is not the expected");
  Assert(NodeA->Previous == NULL, "The previous pointer is not the expected");
  LogSuccess();
}

void NodeChangePreviousTest(void) {
  // Arrange
  Node* NodeA = NodeNew(StringNew("Hello"), sizeof(String), NULL, NULL);
  Node* NodeB = NodeNew(StringNew("to"), sizeof(String), NULL, NodeA);

  // Act
  NodeChangePrevious(NodeB, NodeA);

  // Assert
  Assert(NodeB->Next == NULL, "The next pointer is not the expected");
  Assert(NodeB->Previous == NodeA, "The previous pointer is not the expected");
  LogSuccess();
}

void NodeFreeTest(void) {
  // Arrange
  String* string = StringNew("Hello");
  Node* NodeA = NodeNew(string, sizeof(String), NULL, NULL);

  // Act
  NodeFree(&NodeA);

  Assert(NodeA == NULL, "The Node should be pointing to null");
  LogSuccess();
}
