#include <TFT_eSPI.h>  // Include the TFT_eSPI library for TTGO display

TFT_eSPI tft;  // Create an instance of the TFT_eSPI class

void setup() {
  // Initialize the TFT display
  tft.init();
  tft.setRotation(1);  // Adjust the rotation if needed
  tft.fillScreen(TFT_BLACK);  // Fill the screen with a black background
  //how do i add sleep mode between rounds so it is off for the same amount of time it is on
  
}
void drawStar(int x, int y, uint16_t color) {
  // Draw a star shape at the specified coordinates
  tft.drawLine(x, y - 5, x + 5, y + 5, color);
  tft.drawLine(x + 5, y + 5, x - 5, y, color);
  tft.drawLine(x - 5, y, x + 5, y - 4, color);
  tft.drawLine(x + 5, y - 4, x - 2, y + 5, color);
  tft.drawLine(x - 2, y + 5, x, y - 5, color);
}

void loop() {

  // Display a message at the beginning of each round
  tft.setTextSize(2);
  tft.setTextColor(TFT_BLUE);
  tft.setCursor(10, 10);
  tft.print("Look! I made this  constellation just    for you!");

  // Delay before clearing the message
  delay(5000);  // Adjust the delay as needed
  
  // Clear the screen and message
  tft.fillScreen(TFT_BLACK);
   // Draw 10 random points
  for (int i = 0; i < 6; i++) {
    // Generate random coordinates and color
    int x = random(tft.width());
    int y = random(tft.height());
    uint16_t color = (TFT_BLUE);  // Generate a random 16-bit color
    
    // Draw a random point on the display
    drawStar(x, y, color);
    
    // Delay for a short time between points
    delay(100);  // Adjust the delay as needed
  }
  //keep constellation on the screen so the viewer can see
  delay(3000);
  // Display a message at the beginning of each round
  tft.setTextSize(1);
  tft.setTextColor(TFT_RED);
  tft.setCursor(10, 10);
  tft.print("I hope you like it! Look for it in the night sky");

  tft.setTextSize(2);
  tft.setTextColor(TFT_RED);
  tft.setCursor(10, 50);
  tft.print("Happy Valentines   Day<3");

  // Delay before clearing the message
  delay(3000);  // Adjust the delay as needed

  // Clear the screen after drawing 10 points
  tft.fillScreen(TFT_BLACK);

  // Add a delay before starting the next iteration
  delay(100);  // Adjust the delay as needed
}

