#define NUM_LEDS 24
#define DATA_PIN 5

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(10);
}

int mapping(int x, int y) {
  int light;
  int parity;
  if (y % 2 == 0) {
    parity = 0;
  }
  else if (y % 2 == 1) {
    parity = 1;
  }

  if (parity == 0) {
    light = y * 12 + x;
  }
  else if (parity == 1) {
    light = (y * 12 - 1) + (12 - x);
  }

  return light;
}
void loop() {
  // put your main code here, to run repeatedly:
  int i = mapping(11, 1);
  leds[i] = CHSV(255, 255, 255);
  FastLED.show();

  int j = mapping(11, 0);
  leds[j] = CHSV(0, 255, 255);
  FastLED.show();

  int l = mapping(0, 1);
  leds[l] = CHSV(0, 0, 255);
  FastLED.show();

  int k = mapping(0, 0);
  leds[k] = CHSV(0, 0, 255);
  FastLED.show();
}
