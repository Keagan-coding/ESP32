#include <Neopixel_control.h>

NeopixelControl::NeopixelControl() 
      : LED_Matrix(NUM_COLS, NUM_ROWS, LED_Matrix_Pin, 
                   NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
                   NEO_GRB + NEO_KHZ800) {
        // Initialization code for the matrix
        LED_Matrix.begin();
        LED_Matrix.setTextWrap(false);
        LED_Matrix.setBrightness(10); 
        LED_Matrix.setTextColor(SetColor(GREEN)); // Example color
    }
uint32_t NeopixelControl::SetColor ( COLORS color ){
  switch (color) {
      case RED:         return LED_Matrix.Color(255, 0, 0); 
      case GREEN:       return LED_Matrix.Color(0, 255, 0); 
      case BLUE:        return LED_Matrix.Color(0, 0, 255); 
      case LIGHT_BLUE:  return LED_Matrix.Color(0,255,230); 
      case WHITE:       return LED_Matrix.Color(255, 255, 255); 
      default:          return LED_Matrix.Color(0, 0, 0);
  }
}
void NeopixelControl::DisplayNumber(int num) {
  LED_Matrix.fillScreen(0); 

  LED_Matrix.setCursor(2, 0); 
  LED_Matrix.print(num);
  LED_Matrix.show();
}
void NeopixelControl::SetColoumn(int col, COLORS color) {
  uint32_t colorValue =NeopixelControl::SetColor(color);

  for (int row = 0; row < NUM_ROWS; row++) {
    LED_Matrix.drawPixel(col, row, colorValue);
  }

  LED_Matrix.show();
}
void NeopixelControl::SetRow(int row, COLORS color) {
  uint32_t colorValue = NeopixelControl::SetColor(color);

  for (int col = 0; col < NUM_ROWS; col++) {
    LED_Matrix.drawPixel(col, row, colorValue);
  }

  LED_Matrix.show();
}