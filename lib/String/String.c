#include "String.h"

// Private Declarations
static int calculateLenght(char* value);
static void copySource(char* source, char* destination, uint8 size);

String* StringNew(char* source) {
  uint8 capacity = calculateLenght(source);
  char* string = (char*)malloc((capacity + 1) * sizeof(char));
  copySource(source, string, capacity);

  String* result = (String*)malloc(sizeof(String));
  result->Capacity = capacity;
  result->Beginning = string;

  return result;
}

String* StringClone(String source) {
  return StringNew(source.Beginning);
}

void StringFree(String** this) {
  free((*this)->Beginning);
  (*this)->Beginning = NULL;
  (*this)->Capacity = 0;
  free(*this);
  *this = NULL;
}

Bool StringEqual(String left, String right) {
  if (left.Capacity != right.Capacity) {
    return False;
  }

  for (int i = 0; i < left.Capacity; i++) {
    if (*(left.Beginning + i) != *(right.Beginning + i)) {
      return False;
    }
  }

  return True;
}

Bool StringIsNullOrWhiteSpace(String this) {
  if (this.Beginning == NULL) {
    return False;
  }

  if (this.Capacity == 0) {
    return False;
  }

  return True;
}

String* StringAppend(String left, String right) {
  char* string = malloc((left.Capacity + right.Capacity + 1) * sizeof(char));
  copySource(left.Beginning, string, left.Capacity);
  copySource(right.Beginning, string + left.Capacity, right.Capacity + 1);

  String* result = (String*)malloc(sizeof(String));
  result->Capacity = left.Capacity + right.Capacity;
  result->Beginning = string;

  return result;
}

String* StringSpan(String this, uint8 initial, uint8 final) {
  if (final > this.Capacity) {
    exit(EXIT_FAILURE);
  }

  uint8 distance = (final - initial);
  char* string = malloc((distance + 1) * sizeof(char));
  copySource(this.Beginning + initial, string, distance);
  *(string + distance + 1) = '\0';

  String* result = (String*)malloc(sizeof(String));
  result->Capacity = distance + 1;
  result->Beginning = string;

  return result;
}

// Private Implementations
static int calculateLenght(char* value) {
  int counter = 0;
  char* temp = value;
  while (*value != END_OF_STRING) {
    value++;
    counter++;
  }
  value = temp;
  return counter;
}

// TODO: Generalize lik memcpy function
static void copySource(char* source, char* destination, uint8 size) {
  char* destinationBeginning = destination;
  char* sourceBeginning = source;

  while ((*destination++ = *source++) && size > 0)
    size--;

  destination = destinationBeginning;
  source = sourceBeginning;
}

// TODO: Move to utils.h
void Swap(void* left, void* right) {
  void* temp = left;
  left = right;
  right = temp;
}