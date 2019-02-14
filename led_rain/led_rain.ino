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

const int PIN_FROM = 6;
const int QTY = 6;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  
  for (int i = 0; i<QTY; i++){
    pinMode(PIN_FROM + i, OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  
  for (int i = 0; i<QTY; i++) {
    int pin = PIN_FROM + i;
    digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second

    digitalWrite(PIN_FROM + ((i+1)%QTY), HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(20);
    
    digitalWrite(PIN_FROM + ((i+2)%QTY), HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(20);
    
    digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW  
  }
 
}
