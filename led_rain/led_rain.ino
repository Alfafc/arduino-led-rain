/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

const int LED_PINS[] = {3, 5, 6, 9, 10, 11};
const int LEDS_QTY = sizeof(LED_PINS) / sizeof(LED_PINS[0]);
const int DELAY = 1;

// the setup function runs once when you press reset or power the board
void setup() {
  for (int i = 0; i < LEDS_QTY; i++){
    pinMode(LED_PINS[i], OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {

  for (int currentLed = 0; currentLed < LEDS_QTY; currentLed++) {
    
    int pin = LED_PINS[currentLed];
    
    ligthOn(pin, 2 * DELAY);   // turn the LED on (HIGH is the voltage level)
    
    delay(1 * DELAY);                       // wait for a second

    ligthOff(pin, 3 * DELAY);    // turn the LED off by making the voltage LOW  
  }
}

void ligthOn(int pin, int time){
  for (int i = 0; i<=255; i++) {
    analogWrite(pin, i); 
    delay(time);
  }
}

void ligthOff(int pin, int time){
    for (int i = 255; i>=0; i--) {
    analogWrite(pin, i); 
    delay(time);
  }
}
