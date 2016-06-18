/* *********************************************************************************
 * QRgenerate
 * dependency library :
 *   ESP8266 Oled Driver for SSD1306 display by Daniel Eichborn, Fabrice Weinberg
 * 
 * SDA --> GPIO4 
 * SCL --> GPIO5
***********************************************************************************/

#include <qrgenerate.h>

void setup() {

    Serial.begin(115200);
    Serial.println("");
    Serial.println("Starting...");

    // qrsetup() --> display.init()
    qrsetup();

    // create qrcode
    qrcreate("Hello World.");

}

void loop() { }