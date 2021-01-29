#include "wled.h"

#define BUTTON_A_PIN        D6
#define BUTTON_B_PIN        D7
#define LED_A_PIN           D1
#define LED_B_PIN           D2

/*
 * This v1 usermod file allows you to add own functionality to WLED more easily
 * See: https://github.com/Aircoookie/WLED/wiki/Add-own-functionality
 * EEPROM bytes 2750+ are reserved for your custom use case. (if you extend #define EEPSIZE in const.h)
 * If you just need 8 bytes, use 2551-2559 (you do not need to increase EEPSIZE)
 * 
 * Consider the v2 usermod API if you need a more advanced feature set!
 */

//Use userVar0 and userVar1 (API calls &U0=,&U1=, uint16_t)

//gets called once at boot. Do all initialization that doesn't depend on network here
void userSetup()
{

}

//gets called every time WiFi is (re-)connected. Initialize own network interfaces here
void userConnected()
{

}

//loop. You can use "if (WLED_CONNECTED)" to check for successful connection
void userLoop()
{
    RgbwColor c;
    uint32_t col = strip.getPixelColor(ledCount - 1);
    c.R = col >> 16; c.G = col >> 8; c.B = col; c.W = col >> 24;
    analogWrite(LED_A_PIN, c.R);
    col = strip.getPixelColor(ledCount - 2);
    c.R = col >> 16; c.G = col >> 8; c.B = col; c.W = col >> 24;
    analogWrite(LED_B_PIN, c.R);
}
