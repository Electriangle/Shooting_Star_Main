/* 
 *  ========== Shooting Star Animation ==========
 *  red, green, blue - Choose a color with RGB values (0 to 255).
 *  tail_length - A larger value results in shorter tail.
 *  delay_duration - A larger value results in slower movement speed.
 *  interval - Time interval between new shooting stars (in milliseconds).
*/

unsigned long previousMillis = 0;           // Stores last time LEDs were updated
int count = 0;                              // Stores count for incrementing up to the NUM_LEDs

void shootingStarAnimation(int red, int green, int blue, int tail_length, int delay_duration, int interval){
  unsigned long currentMillis = millis();   // Get the time
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;         // Save the last time the LEDs were updated
    count = 0;                              // Reset the count to 0 after each interval
  }
  if (count < NUM_LEDS) {
    leds[count % (NUM_LEDS+1)].setRGB(red, green, blue);    // Set LEDs with the color value
    count++;
  }
  fadeToBlackBy(leds, NUM_LEDS, tail_length);               // Fade the tail LEDs to black
  FastLED.show();
  delay(delay_duration);                                    // Delay to set the speed of the animation
}
