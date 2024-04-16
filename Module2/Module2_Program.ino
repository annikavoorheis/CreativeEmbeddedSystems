#include <Freenove_WS2812_Lib_for_ESP32.h>

#define LEDS_COUNT  8    // Number of LEDs in the strip
#define LEDS_PIN    17   // Pin connected to the LED strip
#define CHANNEL     0    // Channel of the LED strip

int xyzPins[] = {12, 13, 15}; //x,y,z pins
bool lightsOn = false; // Variable to keep track of LED strip state
uint32_t m_color = 0; // Desired color of the LED strip

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL); // Define the LED strip object

void setup() {
  Serial.begin(115200);
  strip.begin(); // Initialize the LED strip
  pinMode(xyzPins[2], INPUT_PULLUP); //z axis is a button.
}

void loop() {
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);
  Serial.printf("X,Y,Z: %d,\t%d,\t%d\n", xVal, yVal, zVal);
  delay(500);

  // Toggle the lights based on Z axis input
  if (zVal == LOW) { // Assuming LOW when button is pressed
    if (lightsOn) {
      // Turn the lights off
      for (int i = 0; i < LEDS_COUNT; i++) {
        strip.setLedColor(i, 0, 0, 0); // Turn off all LEDs
      }
      strip.show(); // Update the LED strip
      lightsOn = false;
    } else {
      // Turn the lights on
      lightsOn = true;
      // Set the color of the LED strip to m_color
      for (int i = 0; i < LEDS_COUNT; i++) {
        strip.setLedColor(i, m_color >> 16, (m_color >> 8) & 0xFF, m_color & 0xFF);
      }
      strip.show(); // Update the LED strip
    }
  }

  // Change color based on joystick movement only if the lights are on
  if (lightsOn) {
    if (xVal < 100) {
      m_color = 0xFF0000;  // Red
    } else if (xVal > 3000) {
      m_color = 0x0000FF;  // Blue
    } else if (yVal < 100) {
      m_color = 0x00FF00;  // Green
    } else if (yVal > 3000) {
      m_color = 0xFFFF00;  // Yellow
    } else {
      m_color = 0xFF69B4;  // Pink
    }
    // Set the color for each LED in the strip to m_color
    for (int i = 0; i < LEDS_COUNT; i++) {
      strip.setLedColor(i, m_color >> 16, (m_color >> 8) & 0xFF, m_color & 0xFF);
    }
    strip.show(); // Update the LED strip
  }
}
