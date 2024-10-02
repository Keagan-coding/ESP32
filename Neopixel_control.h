#ifndef NEOPIXEL_CONTROL_H
#define NEOPIXEL_CONTROL_H

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>


#define LED_Matrix_Pin 19
#define NUM_ROWS 8
#define NUM_COLS 8


class NeopixelControl {
  public: 
    NeopixelControl();
    Adafruit_NeoMatrix LED_Matrix;
    enum COLORS {
      RED = 1,
      BLUE,
      GREEN,
      LIGHT_BLUE,
      WHITE,
    };
    uint32_t SetColor ( COLORS color );
    void DisplayNumber(int num);
    void SetColoumn(int coloumn, COLORS color);
    void SetRow(int row, COLORS color);

  private:

};

#endif 