#include "../Macros/Macros.h"
#include "../String/String.h"
#include "Result.h"

void ResultOkTest(void);
void ResultErrorTest(void);
void ResultUnwrapTest(void);

int main() {
  ResultOkTest();
  ResultErrorTest();
  ResultUnwrapTest();
}

void ResultOkTest(void) {
  // Arrange
  String* myString = StringNew("Hello");

  // Act
  Result myResult = ResultOk(myString);

  // Assert
  Assert(myString->Beginning == ((String*)myResult.Value)->Beginning,
         "The value is not the expected");
  Assert(myString->Capacity == ((String*)myResult.Value)->Capacity,
         "The value is not the expected");
  Assert(myResult.Ok == True, "Result Ok member should be True");
  LogSuccess();
}

void ResultErrorTest(void) {
  // Arrange
  String* myError = StringNew("Error");

  // Act
  Result myResult = ResultError(&myError);

  // Assert
  Assert(myResult.Error == myError, "The error message is not the expected");
  Assert(myResult.Ok == False, "Result Ok member should be False");
  Assert(myResult.Value == NULL, "Result Value member should be pointing NULL");
  LogSuccess();
}

void ResultUnwrapTest(void) {
  // Arrange
  String* myString = StringNew("Hello");
  Result myResult = ResultOk(myString);
  Result myResultError = ResultError(&myString);

  // Act
  String* myStringResult = (String*)ResultUnwrap(myResult);
  String* myStringError = (String*)ResultUnwrap(myResultError);

  // Assert
  Assert(myString->Beginning == myStringResult->Beginning,
         "The String Beginning is not the expected");
  Assert(myString->Capacity == myStringResult->Capacity,
         "The String Capacity is not the expected");
  Assert(myResult.Ok == True, "Result Ok member should be True");

  Assert(myStringError == NULL,
         "The value of a Result error should be pointing null");
  Assert(myResultError.Value == NULL,
         "Result Value member should be pointing NULL");
  Assert(myResultError.Error == myString,
         "Result Error member should be pointing NULL");
  Assert(myResultError.Ok == False, "Result Ok member should be False");
  LogSuccess();
}
