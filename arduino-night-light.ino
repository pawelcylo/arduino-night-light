/**
* The program below allows using Arduino as controller for baby cradle night light.
* Triggered by stateless button press. Includes PWM LED fading in and out to avoid
* rapid light scene change near sleeping baby.
* 
* Light switching can be triggered during fade in/out so that light can be immediatelly
* turned off without getting full lightness.
* 
* Copyright (C) Paweł Cyło 2016
*/

// Input and output ports configuration
const int button = 7;
const int led = 3;

boolean switchingOnMode = false; // Direction of current light change
int lightValue = 0;              // Current light output PWM value (0-255)

int buttonState;                 // The current buttonReading from the input pin
int lastButtonState = LOW;       // The previous buttonReading from the input pin

long lastStateChangeTime = 0;    // The last time the output pin was toggled
int debounceDelayTime = 50;      // The debounce delay time

void setup() {
  // Define configured pin as input and link it with the internal pull-up resistor
  // to allow connecting press button directly to board, without external resistor
  pinMode(button, INPUT_PULLUP);
}

void loop(){
  // Read the current state of the switch button
  int buttonReading = digitalRead(button);

  // Check if button state has changed because of any reason - press or bounce noise
  if (buttonReading != lastButtonState) {
    // save the time of last state change
    lastStateChangeTime = millis();
  }

  // Check for valueable button state change - ignore any changes that happen before
  // preconfigured debounceDelayTime
  if ((millis() - lastStateChangeTime) > debounceDelayTime) {
    
    // If the button state has changed store the new read value and change light change 
    // direction if the button is pressed down
    if (buttonReading != buttonState) {
      buttonState = buttonReading;
      if (buttonState == HIGH) {
        switchingOnMode = !switchingOnMode;
      }
    }
  }

  // Considering the current light change direction update the light value and wait for
  // a specific time delay to slow down the fading effect
  if (switchingOnMode) {
    lightValue += 1;
    if (lightValue > 255) {
      lightValue = 255;
    }
    delay(25);
  } else {
    lightValue -= 1;
    if (lightValue < 0) {
      lightValue = 0;
    }
    delay(10);
  }

  // Apply the current light value to the LED output pin
  analogWrite(led, lightValue);

  // Store the current button reading value for the next loop
  lastButtonState = buttonReading;
}

