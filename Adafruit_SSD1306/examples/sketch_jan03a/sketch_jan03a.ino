#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define OLED_RESET -1 // Set to -1 if no reset pin is used
#define SCREEN_ADDRESS 0x3C // 0x3C for 128x32, 0x3D for 128x64
#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels

// Initialize the OLED display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Initialize the display
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Loop forever if initialization fails
  }

  // Show the Adafruit splash screen
  display.display();
  delay(2000);

  // Clear the display buffer
  display.clearDisplay();
}

void loop() {
  // Clear the buffer
  display.clearDisplay();

  // Set text properties
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  // Print text to the display buffer
  display.print("OLED Display with STM32 Blue Pill");

  // Update the display with buffer contents
  display.display();

  // Add a small delay to prevent flickering
  delay(1000);
}
