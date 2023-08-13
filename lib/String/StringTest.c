#include "../Macros/Macros.h"
#include "String.h"

#define TEST_STRING "Hello, World!"
#define TEST_STRING_DOUBLED "Hello, World!Hello, World!"
#define TEST_STRING_CAPACITY 13

void StringNewTest(void);
void StringCloneTest(void);
void StringFreeTest(void);
void StringEqualTest(void);
void StringIsNullOrWhiteSpaceTest(void);
void StringAppendTest(void);
void StringSpanTest(void);

int main(void) {
  StringNewTest();
  StringCloneTest();
  StringFreeTest();
  StringEqualTest();
  StringIsNullOrWhiteSpaceTest();
  StringAppendTest();
  StringSpanTest();
  return 1;
}

// TODO: Add a clean function

void StringNewTest(void) {
  // Act
  String* myString = StringNew(TEST_STRING);

  // Assert
  Assert(myString->Capacity == TEST_STRING_CAPACITY, "Wrong capacity");

  char* testString = TEST_STRING;
  for (int i = 0; i < myString->Capacity + 1; i++) {
    Assert(*(testString + i) == *(myString->Beginning + i),
           "The string value is not the expected");
  }

  StringFree(&myString);
  LogSuccess();
}

void StringCloneTest(void) {
  // Arrange
  String* myString = StringNew(TEST_STRING);

  // Act
  String* myStringClone = StringClone(*myString);

  // Assert
  Assert(myString->Capacity == myStringClone->Capacity,
         "The Strings capacities must be equal");
  Assert(myString->Beginning != myStringClone->Beginning,
         "The Strings beginning pointer must be different");

  for (int i = 0; i < myString->Capacity + 1; i++) {
    Assert(*(myStringClone->Beginning + i) == *(myString->Beginning + i),
           "The Strings beginning pointer is not the expected");
  }

  StringFree(&myString);
  StringFree(&myStringClone);
  LogSuccess();
}

void StringFreeTest(void) {
  // Arrange
  String* myString = StringNew(TEST_STRING);

  // Act
  StringFree(&myString);

  // Assert
  Assert(myString == NULL, "The String should point null");
  LogSuccess();
}

void StringEqualTest(void) {
  // Arrange
  String* myString = StringNew(TEST_STRING);
  String* myDifferentString = StringNew("Hello, Gopher!");
  String* myStringCopy = StringClone(*myString);

  // Act
  Bool equalResult = StringEqual(*myString, *myStringCopy);
  Bool differentResult = !StringEqual(*myString, *myDifferentString);

  // Assert
  Assert(equalResult, "The Strings should be equal");
  Assert(differentResult, "The Strings shouldn't be equal");

  StringFree(&myString);
  StringFree(&myDifferentString);
  StringFree(&myStringCopy);
  LogSuccess();
}

void StringIsNullOrWhiteSpaceTest(void) {
  // Arrange
  String* myEmptyString = StringNew("");
  String* myString = StringNew(TEST_STRING);

  // Act
  Bool emptyResult = StringIsNullOrWhiteSpace(*myEmptyString);
  Bool result = StringIsNullOrWhiteSpace(*myString);

  //Assert
  Assert(!emptyResult, "The String should be empty");
  Assert(result, "The String should not be empty");

  StringFree(&myEmptyString);
  StringFree(&myString);
  LogSuccess();
}

void StringAppendTest(void) {
  // Arrange
  String* myStringA = StringNew(TEST_STRING);
  String* myStringB = StringNew(TEST_STRING);
  String* myStringDoubled = StringNew(TEST_STRING_DOUBLED);

  // Act
  String* result = StringAppend(*myStringA, *myStringB);

  // Assert
  Assert(result->Capacity == (myStringB->Capacity + myStringA->Capacity),
         "The resultant String capacity isn't the expected");
  Assert(StringEqual(*result, *myStringDoubled),
         "The resultant String is not the expected");

  StringFree(&myStringA);
  StringFree(&myStringB);
  StringFree(&myStringDoubled);
  LogSuccess();
}

void StringSpanTest(void) {
  // Arrange
  String* myString = StringNew(TEST_STRING);
  String* myStringDoubled = StringNew(TEST_STRING_DOUBLED);
  String* expectedStringA = StringNew("World");
  String* expectedStringB = StringNew("Hello");

  uint8 initialA = 7;
  uint8 finalA = 11;

  uint8 initialB = 13;
  uint8 finalB = 17;

  // Act
  String* resultA = StringSpan(*myString, initialA, finalA);
  String* resultB = StringSpan(*myStringDoubled, initialB, finalB);

  // Arrange
  Assert(resultA->Capacity == expectedStringA->Capacity,
         "The String capacity is not the expected");
  Assert(StringEqual(*resultA, *expectedStringA),
         "The resultant String is not the expected");

  Assert(resultB->Capacity == expectedStringB->Capacity,
         "The String capacity is not the expected");
  Assert(StringEqual(*resultB, *expectedStringB),
         "The resultant String is not the expected");

  StringFree(&myString);
  StringFree(&myStringDoubled);
  StringFree(&expectedStringA);
  StringFree(&expectedStringB);
  LogSuccess();
}
