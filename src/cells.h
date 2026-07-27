#ifndef CELLS_H
#define CELLS_H

#include <graphx.h>

typedef struct {
  int base_index, size;
} base_index_and_size;

typedef struct {
  int x, y;
} Coord;

typedef struct {
  const bool *cells;
  size_t size;
} Base;

extern Base bases[];
extern size_t bases_len;
extern Coord coords[];
extern size_t coords_len;

#endif
