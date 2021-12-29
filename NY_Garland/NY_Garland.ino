#include <FastLED.h>
#define NUM_LEDS 300      // Количество светодиодов в ленте
#define DATA_PIN 5        // Сигнальный пин
#define LED_TYPE WS2812B  // Тип светодиодов
#define DELAY_TIME 1      // Множетель скорости рабботы еффектов(чем выше тем медленнее)



CRGB leds[NUM_LEDS];
byte counter;
int randNumber;
int effectGenerator;
int randomStartLightPosition;

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);
  Serial.println("Запущен");
  delay(3000);
}

unsigned long timing;
void loop() {
  RGBcontrol();
}

void RGBcontrol() {
  FastLED.clear();
  for (int j = 0; j < 255; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(i - (j * 2), 255, 50);
    }
    if (counter >= 20) {
      randomStartLightPosition = random(150, 300);
      leds[randomStartLightPosition].setRGB(255, 255, 255);
      FastLED.show();
      delay(DELAY_TIME * 1);
      leds[randomStartLightPosition].setRGB(0, 0, 0);
      counter = 0;
    }
    counter++;
    FastLED.show();
    effectGenerator = random(1, 2000);
    Serial.println(effectGenerator);

    if (effectGenerator == 500) {
      randNumber = random(100, NUM_LEDS);
      for (int i = 0; i < NUM_LEDS; i++) {
        leds[i].setRGB(50, 255, 0);
        if (i >= 1) {
          leds[i - 1].setRGB(30, 200, 0);
        }
        if (i >= 2) {
          leds[i - 2].setRGB(20, 150, 0);
        }
        if (i >= 3) {
          leds[i - 3].setRGB(10, 100, 0);
        }
        if (i >= 4) {
          leds[i - 4].setRGB(5, 50, 0);
        }
        if (i >= 5) {
          leds[i - 5].setRGB(2, 40, 0);
        }
        if (i >= 6) {
          leds[i - 6].setRGB(1, 30, 0);
        }
        if (i >= 7) {
          leds[i - 7].setRGB(0, 20, 0);
        }
        if (i >= 8) {
          leds[i - 8].setRGB(0, 15, 0);
        }
        if (i >= 9) {
          leds[i - 9].setRGB(0, 10, 0);
        }
        if (i >= 10) {
          leds[i - 10].setRGB(0, 5, 0);
        }
        if (i >= 11) {
          leds[i - 10].setRGB(0, 2, 0);
        }
        if (i >= 12) {
          leds[i - 10].setRGB(0, 1, 0);
        }
        FastLED.show();
        delay(DELAY_TIME * 10);
      }
      for (int z = 0; z < NUM_LEDS
      ; z++) {
        for (int x = 0; x < z; x++) {
          leds[x] = CHSV(x - (z * 2), 255, 50);
        }
        FastLED.show();
          delay(DELAY_TIME * 2);
      }
    }

    if (effectGenerator >= 1995) {
      randNumber = random(150, NUM_LEDS - 15);
      for (int i = randNumber; i <= randNumber + 10; i++) {
        leds[i].setRGB(255, 255, 255);
      }
      FastLED.show();
      delay(DELAY_TIME * 50);
      for (int i = randNumber - 9; i <= randNumber + 10; i++) {
        leds[i].setRGB(0, 0, 1);
      }
      FastLED.show();
      for (int i = randNumber; i <= NUM_LEDS; i++) {
        leds[i].setRGB(0, 0, 255);
        if (i >= 1) {
          leds[i - 1].setRGB(0, 0, 255);
        }
        if (i >= 2) {
          randomStartLightPosition = random(200, 255);
          leds[i - 2].setRGB(0, 0, randomStartLightPosition);
        }
        if (i >= 3) {
          randomStartLightPosition = random(150, 255);
          leds[i - 3].setRGB(0, 0, randomStartLightPosition);
        }
        if (i >= 4) {
          randomStartLightPosition = random(100, 255);
          leds[i - 4].setRGB(0, 0, randomStartLightPosition);
        }
        if (i >= 5) {
          randomStartLightPosition = random(50, 255);
          leds[i - 5].setRGB(0, 0, randomStartLightPosition);
        }
        if (i >= 6) {
          randomStartLightPosition = random(40, 255);
          leds[i - 6].setRGB(0, 0, randomStartLightPosition);
        }
        if (i >= 7) {
          randomStartLightPosition = random(30, 255);
          leds[i - 7].setRGB(0, 0, randomStartLightPosition);
        }
        if (i >= 8) {
          randomStartLightPosition = random(20, 255);
          leds[i - 8].setRGB(0, 0, randomStartLightPosition);
        }
        if (i >= 9) {
          randomStartLightPosition = random(10, 255);
          leds[i - 9].setRGB(0, 0, randomStartLightPosition);
        }
        if (i >= 10) {
          randomStartLightPosition = random(1, 10);
          leds[i - 10].setRGB(0, 0, randomStartLightPosition);
        }
        FastLED.show();
        delay(DELAY_TIME * 1);
        randomStartLightPosition = random(0, 255);
        if (randomStartLightPosition <= 10) {
          leds[i - 3].setRGB(255, 255, 255);
          leds[i - 2].setRGB(255, 255, 255);
          leds[i - 1].setRGB(255, 255, 255);
          leds[i].setRGB(255, 255, 255);
          leds[i + 1].setRGB(255, 255, 255);
          leds[i + 2].setRGB(255, 255, 255);
          leds[i + 3].setRGB(255, 255, 255);
          FastLED.show();
          delay(DELAY_TIME * 5); +
          leds[i - 5].setRGB(0, 0, 1);
          leds[i - 4].setRGB(0, 0, 1);
          leds[i - 3].setRGB(0, 0, 1);
          leds[i - 2].setRGB(0, 0, 1);
          leds[i - 1].setRGB(0, 0, 1);
          leds[i].setRGB(0, 0, 1);
          leds[i + 1].setRGB(0, 0, 1);
          leds[i + 2].setRGB(0, 0, 1);
          leds[i + 3].setRGB(0, 0, 1);
          leds[i + 4].setRGB(0, 0, 1);
          leds[i + 5].setRGB(0, 0, 1);
        }
        if (randomStartLightPosition >= 249) {
          break;
        }
      }
    }
  }
}
