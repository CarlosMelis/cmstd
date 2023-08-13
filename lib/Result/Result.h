#ifndef CMSTD_RESULT_H
#define CMSTD_RESULT_H

#include "../Bool/Bool.h"
#include "../String/String.h"

typedef struct {
  Bool Ok;
  String* Error;
  void* Value;
} Result;

Result ResultOk(void* value);
Result ResultError(String** errorMessage);
void* ResultUnwrap(Result result);

#endif
