#include "fractal_drawer.h"
#include <keypadc.h>

void init(void) {
  gfx_ZeroScreen();
  gfx_SetColor(0xFF);

  draw_fractal(GFX_LCD_HEIGHT);
}

void loop(void) {}

int main(void) {
  gfx_Begin();

  init();

  do {
    kb_Scan();
    loop();
  } while (kb_Data[6] != kb_Clear && kb_Data[1] != kb_Mode &&
           kb_Data[1] != kb_Del);
  // exit on annul, mode or delete key press

  gfx_End();

  return 0;
}
