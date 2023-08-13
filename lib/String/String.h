#ifndef CMSTD_STRING
#define CMSTD_STRING

#include "../Bool/Bool.h"
#include "../Macros/Macros.h"
#include "../PrimitiveTypes/PrimitiveTypes.h"

#define END_OF_STRING '\0'

typedef struct String {
  char* Beginning;
  int Capacity;
} String;

/* Constructor */
String* StringNew(char* source);

/* Creates a new String struct identical to the original */
String* StringClone(String source);

/* Deallocates string from memory */
void StringFree(String** this);

/* Checks if 2 String structures are equal */
Bool StringEqual(String left, String right);

/* Concatenates 2 String structures*/
String* StringAppend(String left, String right);

/* Checks if the String structure is null or white space*/
Bool StringIsNullOrWhiteSpace(String this);

/* Returns a substring of the original String */
String* StringSpan(String this, uint8 initial, uint8 final);

#endif
