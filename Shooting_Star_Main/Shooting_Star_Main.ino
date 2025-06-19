/*
 * Title: Shooting_Star_Main
 * 
 * Description:
 *      - This sketch was created for controling a WS2812B LED light strip (or similar) using the FastLED library. 
 *      
 * Author: Electriangle
 *      - Channel: https://www.youtube.com/@Electriangle
 *      - Shooting Star LED Animation Video: https://www.youtube.com/watch?v=tcjGnPcd1oU
 *      
 * License: MIT License
 *      - Copyright (c) 2022 Electriangle
 *
 * Date Created: 11/30/2022
 * Last Updated: 11/30/2022
*/

#include "FastLED.h"

#define NUM_LEDS  150    // Enter the total number of LEDs on the strip
#define PIN       7      // The pin connected to Din to control the LEDs

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 1500);    // Set power limit of LED strip to 5V, 1500mA
  FastLED.clear();                                    // Initialize all LEDs to "OFF"
}

void loop() {
  // A simple White Shooting Star
  shootingStarAnimation(255, 255, 255, random(10, 60), random(5, 40), random(2000, 8000), 1);

  // Try changing the arguments. Uncomment this line of code to try out a fully randomized animation example:
//    shootingStarAnimation(random(0, 255), random(0, 255), random(0, 255), random(10, 60), random(5, 40), random(2000, 8000), 1);
}
