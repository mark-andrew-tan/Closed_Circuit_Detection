/*
  Blink without Delay

  Turns on and off a light emitting diode (LED) connected to a digital pin,
  without using the delay() function. This means that other code can run at the
  same time without being interrupted by the LED code.

  The circuit:
  - Use the onboard LED.
  - Note: Most Arduinos have an on-board LED you can control. On the UNO, MEGA
    and ZERO it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN
    is set to the correct LED pin independent of which board is used.
    If you want to know what pin the on-board LED is connected to on your
    Arduino model, check the Technical Specs of your board at:
    https://www.arduino.cc/en/Main/Products

  created 2005
  by David A. Mellis
  modified 8 Feb 2010
  by Paul Stoffregen
  modified 11 Nov 2013
  by Scott Fitzgerald
  modified 9 Jan 2017
  by Arturo Guadalupi

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay
*/

// constants won't change. Used here to set a pin number:
const int OpenPin = 8;     // the number of the Open pin
const int ClosePin = 7;     // the number of the Closed pin

const int ledPin =  LED_BUILTIN;// the number of the LED pin

// constants won't change:
const long interval = 500;           // interval at which to blink (milliseconds)
const long LED_on_interval = 2500;
// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated
unsigned long timer_start_Millis = 0;        // will store last time LED was updated
unsigned long curr_prev_interval = 0;        // will store last time LED was updated

// variables will change:
int OpenState = 0;         // variable for reading the open status
int CloseState = 0;         // variable for reading the close status

bool start_counting = false;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  // initialize the Open pin as an input:
  pinMode(OpenPin, INPUT);
  // initialize the Close pin as an input:
  pinMode(ClosePin, INPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();
  Serial.print("CURR: ");
  Serial.println(currentMillis);
  Serial.print("LED STATE: ");
  Serial.print(ledState);

  // read the state of the Open value:
  OpenState = digitalRead(OpenPin);
  // read the state of the Close value:
  CloseState = digitalRead(ClosePin);
  // --- check if the door is closed ---

  if (CloseState == HIGH) {
    Serial.print(" // CLOSED // ");
    timer_start_Millis = currentMillis;

  }
  // If it is, do not update timer_start_Millis
  // this is our method of starting timer:
  if (OpenState == HIGH) {
    Serial.print(" // PUSHED // ");

    // If not pushed,
    // keep timer_start_Millis update to prevent blink condition
    // same for prevMillis
  } else {
    timer_start_Millis = currentMillis;
    previousMillis = currentMillis;
  }

  // check if need to blink LED

  if (currentMillis - timer_start_Millis >= LED_on_interval) {
    // Serial.print("DO BLINK //");

    // THIS WILL ALWAYS BE TRUE WHILE PUSHED IS TRUE
    // Once pushed is FALSE, timer_start_Millis is reset.

    // we want to blink LED.
    // so we do not constant update previousMillis and run BLINK CODE

    // BLINK CODE
    curr_prev_interval = currentMillis - previousMillis;
    if (curr_prev_interval >= interval) {
      // save the last time you blinked the LED
      previousMillis = currentMillis;

      // if the LED is off turn it on and vice-versa:
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }

      // set the LED with the ledState of the variable:
      digitalWrite(ledPin, ledState);

    }

  } else {

    if (ledState == HIGH) {
        ledState = LOW;
      } 
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
    
  }

}
