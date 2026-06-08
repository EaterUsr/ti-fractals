#include <graphx.h>
#include <keypadc.h>

void init(void) {
  gfx_ZeroScreen();
  gfx_SetColor(0xFF);
}

void loop(void) {
  // draw initial square
  gfx_SetPixel(0, 0);
  gfx_SetPixel(1, 0);
  gfx_SetPixel(2, 0);
  gfx_SetPixel(0, 1);
  gfx_SetPixel(2, 1);
  gfx_SetPixel(0, 2);
  gfx_SetPixel(1, 2);
  gfx_SetPixel(2, 2);

  // duplicate square
  int size = 3;
  uint8_t screen_buffer = gfx_GetDraw();

  while (size < GFX_LCD_WIDTH && size < GFX_LCD_HEIGHT) {
    gfx_CopyRectangle(screen_buffer, screen_buffer, 0, 0, size, 0, size, size);
    gfx_CopyRectangle(screen_buffer, screen_buffer, 0, 0, size * 2, 0, size, size);
    gfx_CopyRectangle(screen_buffer, screen_buffer, 0, 0, 0, size, size, size);
    gfx_CopyRectangle(screen_buffer, screen_buffer, 0, 0, size * 2, size, size, size);
    gfx_CopyRectangle(screen_buffer, screen_buffer, 0, 0, 0, size * 2, size, size);
    gfx_CopyRectangle(screen_buffer, screen_buffer, 0, 0, size, size * 2, size, size);
    gfx_CopyRectangle(screen_buffer, screen_buffer, 0, 0, size * 2, size * 2, size, size);
    size *= 3;
  }

  gfx_SetDraw(screen_buffer);
}

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
