// A basic everyday NeoPixel strip test program.

// NEOPIXEL BEST PRACTICES for most reliable operation:
// - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// - AVOID connecting NeoPixels on a LIVE CIRCUIT. If you must, ALWAYS
//   connect GROUND (-) first, then +, then data.
// - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
//   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// (Skipping these may work OK on your workbench but can fail in the field)

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6
#define LED_PIN_TWO 10

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 64

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripTwo(LED_COUNT, LED_PIN_TWO, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)


// setup() function -- runs once at startup --------------------------------

int leftFlag[] = {0,0,0,0,1,0,0,0,
                  0,0,1,1,1,0,0,0,
                  1,1,1,1,1,1,1,1,
                  1,1,1,1,1,1,1,0,
                  0,0,1,1,0,1,1,0,
                  1,1,0,0,0,1,1,0,
                  0,1,0,0,0,0,0,1,
                  0,0,0,0,0,0,0,0};

int rightFlag[] = {0,0,1,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,
                   1,0,0,1,0,0,0,0,
                   0,0,0,0,0,0,0,0,
                   0,0,0,1,0,0,0,0,
                   0,0,0,0,0,0,0,0,
                   0,0,1,0,0,0,0,0,
                   0,0,0,0,0,0,0,1};

int leftLGBTFLAG[] = {0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,
                      1,1,1,1,1,1,1,1,
                      2,2,2,2,2,2,2,2,
                      3,3,3,3,3,3,3,3,
                      4,4,4,4,4,4,4,4,
                      5,5,5,5,5,5,5,5,
                      5,5,5,5,5,5,5,5};

int rightLGBTFLAG[] = {0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,
                      1,1,1,1,1,1,1,1,
                      2,2,2,2,2,2,2,2,
                      3,3,3,3,3,3,3,3,
                      4,4,4,4,4,4,4,4,
                      5,5,5,5,5,5,5,5,
                      5,5,5,5,5,5,5,5};


void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  stripTwo.begin();
  strip.show();            // Turn OFF all pixels ASAP
  stripTwo.show();
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  stripTwo.setBrightness(50);
  Serial.begin(9600);

}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() 
{
    ChineseFlagLeft(leftFlag, strip.Color(127, 0, 0), strip.Color(127,127,0), 1);
    ChineseFlagRight(rightFlag, stripTwo.Color(127,0,0), stripTwo.Color(127,127,10), 1);
    delay(50);
    ChineseFlagLeft(leftFlag, strip.Color(115, 0, 0), strip.Color(95,95,0), 1);
    ChineseFlagRight(rightFlag, stripTwo.Color(115,0,0), stripTwo.Color(95,95,0), 1);
    delay(50);
    ChineseFlagLeft(leftFlag, strip.Color(120, 0, 0), strip.Color(95,95,0), 1);
    ChineseFlagRight(rightFlag, stripTwo.Color(120,0,0), stripTwo.Color(95,95,0), 1);
    delay(50);
    ChineseFlagLeft(leftFlag, strip.Color(95, 0, 0), strip.Color(95,95,0), 1);
    ChineseFlagRight(rightFlag, stripTwo.Color(95,0,0), stripTwo.Color(95,95,0), 1);
    delay(50);
    
//    solidColorPanelOne(strip.Color(255,57,57), 10);
//    solidColorPanelTwo(strip.Color(255,57,57), 10);
//    strip.show();
//    stripTwo.show();
//    delay(20000);
    //LgbtFlagOne(leftLGBTFLAG, strip.Color(255,0,0), strip.Color(255,128,0), strip.Color(255,255,0), strip.Color(0,255,0), strip.Color(0,0,255), strip.Color(76,0,153),10);
    //LgbtFlagTwo(rightLGBTFLAG, strip.Color(255,0,0), strip.Color(255,128,0), strip.Color(255,255,0), strip.Color(0,255,0), strip.Color(0,0,255), strip.Color(76,0,153),10);
    //delay(1250);

}


void ChineseFlagLeft(int colorArray[], uint32_t red, uint32_t yellow, int wait )
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    if (colorArray[i] == 0)
    {
      strip.setPixelColor(i, red);
      strip.show();
      delay(wait);
    }
    else if (colorArray[i] == 1)
    {
      strip.setPixelColor(i, yellow);
      strip.show();
      delay(wait);
    }
  }
}


void ChineseFlagRight(int colorArray[], uint32_t red, uint32_t yellow, int wait )
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    if (colorArray[i] == 0)
    {
      stripTwo.setPixelColor(i, red);
      stripTwo.show();
      delay(wait);
    }
    else if (colorArray[i] == 1)
    {
      stripTwo.setPixelColor(i, yellow);
      stripTwo.show();
      delay(wait);
    }
  }
}

void solidColorPanelOne(uint32_t color, int wait)
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}

void solidColorPanelTwo(uint32_t color, int wait)
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    stripTwo.setPixelColor(i, color);
    stripTwo.show();
    delay(wait);
  }
}

void LgbtFlagOne(int colorArray[], uint32_t red, uint32_t orange, uint32_t yellow, uint32_t green, uint32_t blue, uint32_t purple, int wait)
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    if (colorArray[i] == 0)
    {
      strip.setPixelColor(i, red);
    }
    else if (colorArray[i] == 1)
    {
      strip.setPixelColor(i, orange);
    }
    else if (colorArray[i] == 2)
    {
      strip.setPixelColor(i, yellow);
    }
    else if (colorArray[i] == 3)
    {
      strip.setPixelColor(i, green);
    }
    else if (colorArray[i] == 4)
    {
      strip.setPixelColor(i, blue);
    }
    else if (colorArray[i] == 5)
    {
      strip.setPixelColor(i,purple);
    }
    strip.show();
  }
}



void LgbtFlagTwo(int colorArray[], uint32_t red, uint32_t orange, uint32_t yellow, uint32_t green, uint32_t blue, uint32_t purple, int wait)
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    if (colorArray[i] == 0)
    {
      stripTwo.setPixelColor(i, red);
    }
    else if (colorArray[i] == 1)
    {
      stripTwo.setPixelColor(i, orange);
    }
    else if (colorArray[i] == 2)
    {
      stripTwo.setPixelColor(i, yellow);
    }
    else if (colorArray[i] == 3)
    {
      stripTwo.setPixelColor(i, green);
    }
    else if (colorArray[i] == 4)
    {
      stripTwo.setPixelColor(i, blue);
    }
    else if (colorArray[i] == 5)
    {
      stripTwo.setPixelColor(i,purple);
    }
    stripTwo.show();
  }
}
