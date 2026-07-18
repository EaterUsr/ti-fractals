#include <graphx.h>
#include <keypadc.h>

typedef struct {
  int base_index, size;
} base_index_and_size;

base_index_and_size get_base_index(int power) {
  while (true) {
    if (power > GFX_LCD_HEIGHT) {
      base_index_and_size res;

      res.base_index = 1;
      res.size = 2 * (power / 3);

      return res;
    } else if (2 * power > GFX_LCD_HEIGHT) {
      base_index_and_size res;

      res.base_index = 0;
      res.size = power;

      return res;
    }

    power *= 3;
  }
}

void replicate_fractal(uint8_t screen_buffer, int size, int x, int y) {
  /*
   * -------------
   * | 1 | 2 | 3 |
   * -------------
   * | 4 | 5 | 6 |
   * -------------
   * | 7 | 8 | 9 |
   * -------------
   */
  gfx_CopyRectangle(screen_buffer, screen_buffer, x, y, x + size, y, size,
                    size); // 2
  gfx_CopyRectangle(screen_buffer, screen_buffer, x, y, x + size * 2, y, size,
                    size); // 3
  gfx_CopyRectangle(screen_buffer, screen_buffer, x, y, x, y + size, size,
                    size); // 4
  gfx_CopyRectangle(screen_buffer, screen_buffer, x, y, x + size * 2, y + size,
                    size, size); // 6
  gfx_CopyRectangle(screen_buffer, screen_buffer, x, y, x, y + size * 2, size,
                    size); // 7
  gfx_CopyRectangle(screen_buffer, screen_buffer, x, y, x + size, y + size * 2,
                    size, size); // 8
  gfx_CopyRectangle(screen_buffer, screen_buffer, x, y, x + size * 2,
                    y + size * 2, size, size); // 9

  size *= 3;
}

void draw_fractal() {
  const int power = 3;

  base_index_and_size res = get_base_index(power);

  int x = GFX_LCD_WIDTH / 2 - res.size / 2;
  int y = GFX_LCD_HEIGHT / 2 - res.size / 2;

  if (res.base_index == 0) {
    gfx_SetPixel(x, y);
  } else {
    gfx_SetPixel(x, y);
    gfx_SetPixel(x, y + 1);
    gfx_SetPixel(x + 1, y);
    gfx_SetPixel(x + 1, y + 1);
  }

  uint8_t screen_buffer = gfx_GetDraw();
  int size = res.base_index + 1;

  while (size * power < GFX_LCD_HEIGHT) {
    replicate_fractal(screen_buffer, size, x, y);
    size *= power;
  }

  gfx_SetDraw(screen_buffer);
}

void init() {
  gfx_ZeroScreen();
  gfx_SetColor(0xFF);

  draw_fractal();
}

void loop(void) {}

int main(void) {
  gfx_Begin();

  init();

  do {
    kb_Scan();
    loop();
  } while (kb_Data[6] != kb_Clear);

  gfx_End();

  return 0;
}
