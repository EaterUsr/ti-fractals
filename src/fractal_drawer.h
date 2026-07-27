#ifndef FRACTAL_DRAWER_H
#define FRACTAL_DRAWER_H

#include "cells.h"

int get_base_index(int power, const int factors[], size_t factors_len, int max_size);
void replicate_fractal(uint8_t screen_buffer, int size, int x, int y,
                       const Coord coords[], size_t len);
void draw_base(int origin_x, int origin_y, const bool cells[], size_t size);
int get_final_size(size_t base_size, int power, int max_size);
void draw_fractal(int max_size);

#endif
