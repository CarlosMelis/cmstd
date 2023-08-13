#ifndef CMSTD_MACROS_H
#define CMSTD_MACROS_H

#include <stdio.h>
#include <stdlib.h>

#define ERROR_PREFIX "[-]"
#define SUCCESS_PREFIX "[+]"

#define Assert(condition, message)                                          \
  do {                                                                      \
    if (!(condition)) {                                                     \
      fprintf(stderr, "%s %s \n\t>> File: %s <-> Line: %d\n", ERROR_PREFIX, \
              message, __FILE__, __LINE__);                                 \
      exit(EXIT_FAILURE);                                                   \
    }                                                                       \
  } while (0)

#define LogSuccess() fprintf(stdout, "%s %s\n", SUCCESS_PREFIX, __func__)

#endif