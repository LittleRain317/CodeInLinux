#ifndef PATH_ALLOC_H_
#include "../include/apue.h"
#include <errno.h>
#include <limits.h>

#ifdef PATH_MAX
static long pathmax = PATH_MAX;
#else
static long pathmax = 0;
#endif

static long posix_version = 0;
static long xsi_version = 0;

#define PATH_MAX_GUESS 	1024

char* path_alloc(size_t *sizep); /* also return allocated size, if nonnull */
#define PATH_ALLOC_H_
#endif
