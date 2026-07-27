#include "fractal_drawer.h"
#include "cells.h"
#include <debug.h>
#include <graphx.h>
#include <stdint.h>

int get_base_index(int power, const int factors[], size_t factors_len, int max_size) {
  float current_size = max_size;
  float part_max = 0;
  int base_index_max = 0;

  for (int i = (int)factors_len - 1; i >= 0; i--) {
    while (factors[i] < current_size) {
      current_size /= power;
    }
    current_size *= power;

    float part = (float)factors[i] / current_size;

    if (part > part_max) {
      part_max = part;
      base_index_max = i;
    }
  }

  return base_index_max;
}

void replicate_fractal(uint8_t screen_buffer, int size, int x, int y,
                       const Coord coords[], size_t len) {
  for (size_t i = 0; i < len; ++i) {
    gfx_CopyRectangle(screen_buffer, screen_buffer, x, y,
                      x + coords[i].x * size, y + coords[i].y * size, size,
                      size);
  }
}

void draw_base(int origin_x, int origin_y, const bool cells[], size_t size) {
  for (size_t x = 0; x < size; ++x) {
    for (size_t y = 0; y < size; ++y) {
      if (cells[x * size + y])
        gfx_SetPixel(origin_x + x, origin_y + y);
    }
  }
}

int get_final_size(size_t base_size, int power, int max_size) {
  int current_size = base_size;

  while (current_size < max_size) {
    current_size *= power;
  }

  return current_size / power;
}

void draw_fractal(int max_size) {
  int factors[bases_len] = {};
  int power = 3;

  for (size_t i = 0; i < bases_len; ++i) {
    factors[i] = bases[i].size;
  }

  int base_index = get_base_index(power, factors, bases_len, max_size);

  int final_size = get_final_size(bases[base_index].size, power, max_size);

  int x = GFX_LCD_WIDTH / 2 - final_size / 2;
  int y = GFX_LCD_HEIGHT / 2 - final_size / 2;

  Base base = bases[base_index];

  draw_base(x, y, base.cells, base.size);

  uint8_t screen_buffer = gfx_GetDraw();
  int size = bases[base_index].size;

  while (size * power < max_size) {
    replicate_fractal(screen_buffer, size, x, y, coords, coords_len);
    size *= power;
  }

  gfx_SetDraw(screen_buffer);
}
