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
const int TAIL_LONG = 3;

// the setup function runs once when you press reset or power the board
void setup() {
  for (int i = 0; i < LEDS_QTY; i++){
    pinMode(LED_PINS[i], OUTPUT);
  }

  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {

  int previousLedON = 0;
  for (int currentLedON = 0; currentLedON < LEDS_QTY; currentLedON++) {
        
    for (int i = 0; i < LEDS_QTY; i++) {
      setIntensityFor(i, previousLedON, currentLedON, LEDS_QTY);
    }

    previousLedON = currentLedON;
    delay(1 * DELAY);
  }
  
//  setIntensityFor(0, 0, LEDS_QTY);
  delay(1000);
}

int setIntensityFor(int led, int previousLedON, int currentLedON, int total){
  int previousValue = getIntensityFor(led, previousLedON, total);
  int newValue = getIntensityFor(led, currentLedON, total);

  Serial.println(previousLedON);
  Serial.println(currentLedON);
  Serial.println(led);
  
  Serial.println(previousValue);
  Serial.println(newValue);
  Serial.println(100000000);

//  int i = previousValue;
//  while (i !=  newValue) {
//      analogWrite(LED_PINS[led], i); 
//
//      if(previousValue < newValue)
//        i++;
//      else
//        i--;
//      delay(20);
//  }   
 delay(1200);
  analogWrite(LED_PINS[led], newValue);  
}

int getIntensityFor(int led, int currentLedON, int total){  

  int distance;
  if(currentLedON >= led ) distance = currentLedON - led;
  else return 0;
//  else distance = (led - currentLedON + total) % total;

  return 255 * (float) (min(distance, TAIL_LONG) / TAIL_LONG);
}
