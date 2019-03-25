/*
  Led rain

  by Fernando Costantini
  
*/

const int LED_PINS[] = {3, 5, 6, 9, 10, 11};
const int LEDS_QTY = sizeof(LED_PINS) / sizeof(LED_PINS[0]);
const int DELAY = 50;
const int TAIL_LONG = 4;

// the setup function runs once when you press reset or power the board
void setup() {
  for (int i = 0; i < LEDS_QTY; i++){
    pinMode(LED_PINS[i], OUTPUT);
  }

  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {

//    // to test leds order
//    for (int led = 0; led < LEDS_QTY; led++) {
//      analogWrite(LED_PINS[led], 150);  
//      delay(500);
//      analogWrite(LED_PINS[led], 255);  
//    }

  // first loop will carry the ligth to every led
  int previousLedON = 0;
  for (int currentLedON = 0; currentLedON < LEDS_QTY + TAIL_LONG + 1; currentLedON++) {

    // this will set every LED a value (could be anything between 0 and 255) according to the led ON
    for (int i = 0; i < LEDS_QTY; i++) {
      setIntensityFor(i, previousLedON, currentLedON, LEDS_QTY);
    }

    previousLedON = currentLedON;
    delay(DELAY);
  }

  delay(1000);
}

int setIntensityFor(int led, int previousLedON, int currentLedON, int total){
  int previousValue = getIntensityFor(led, previousLedON, total);
  int newValue = getIntensityFor(led, currentLedON, total);
 
  analogWrite(LED_PINS[led], newValue);
}

int getIntensityFor(int led, int currentLedON, int total){  

  int distance= currentLedON - led;
  if (distance <= 0 || distance > TAIL_LONG) return 0;

  return 255 * (float) ((float)1 / (float)distance);
}
