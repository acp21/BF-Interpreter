#ifndef BF_INTERPRETER_H
#define BF_INTERPRETER_H

#include <aio.h>

typedef struct brackets{
    off_t first;
    off_t second;
} brackets_t;

typedef struct node{
    off_t offset;
    node_t *next;
} node_t;

#endif