#include "cells.h"
#include <graphx.h>

static bool cells_0[] = {true};
bool cells_1[] = {true, true, true, true};
bool cells_2[] = {
  true,  true,  true,  true,
  true,  false, false, true,
  true,  false, false, true,
  true,  true,  true,  true,
};
bool cells_3[] = {
  true,  true,  true,  true,  true,
  true,  false, false, false, true,
  true,  false, false, false, true,
  true,  false, false, false, true,
  true,  true,  true,  true,  true,
};
bool cells_4[] = {
    true,  true,  true,  true,  true,  true,  true,
    true,  true,  true,  true,  true,  true,  true,
    true,  true,  false, false, false, true,  true,
    true,  true,  false, false, false, true,  true,
    true,  true,  false, false, false, true,  true,
    true,  true,  true,  true,  true,  true,  true,
    true,  true,  true,  true,  true,  true,  true,
};
bool cells_5[] = {
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  false, false, false, false, true,  true,
  true,  true,  false, false, false, false, true,  true,
  true,  true,  false, false, false, false, true,  true,
  true,  true,  false, false, false, false, true,  true,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  true,  true,  true,  true,  true,
};

Base bases[] = {
  (Base) {cells_0, 1},
  (Base) {cells_1, 2},
  (Base) {cells_2, 4},
  (Base) {cells_3, 5},
  (Base) {cells_4, 7},
  (Base) {cells_5, 8}
};
size_t bases_len = sizeof(bases) / sizeof(bases[0]);

Coord coords[] = {
  (Coord) {1, 0},
  (Coord) {2, 0},
  (Coord) {0, 1},
  (Coord) {2, 1},
  (Coord) {0, 2},
  (Coord) {1, 2},
  (Coord) {2, 2}
};
size_t coords_len = sizeof(coords) / sizeof(coords[0]);
