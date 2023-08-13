#include "Result.h"

Result ResultOk(void* value) {
  Result result = {};
  result.Value = value;
  result.Error = StringNew("");
  result.Ok = True;
  return result;
}

Result ResultError(String** errorMessage) {
  Result result = {};
  result.Value = NULL;
  result.Error = *errorMessage;
  result.Ok = False;
  return result;
}

void* ResultUnwrap(Result result) {
  return result.Value;
}
