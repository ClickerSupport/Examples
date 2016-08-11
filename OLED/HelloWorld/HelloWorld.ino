/*
 * Prints "Hello World" on the OLED along with the return value of millis()
 * every 100ms.
 *
 * Needs SSD1306 support from DisplayCore
 *
 * * https://github.com/MajenkoLibraries/DisplayCore
 */

#include <DisplayCore.h>
#include <DSPI.h>
#include <SSD1306.h>

DSPI0 spi;
CLICK_OLED_B oled(spi, PIN_C1_CS, PIN_C1_PWM, PIN_C1_RST);

void setup() {
    oled.initializeDevice();
    oled.fillScreen(Color::Black);
    oled.setCursor(0, 0);
    oled.print("Hello World");
}

void loop() {
    oled.setCursor(0, 16);
    oled.print(millis());
    delay(100);
}

