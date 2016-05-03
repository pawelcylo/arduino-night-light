# Arduino Baby Cradle Night Light

Arduino powered night light designed to work in baby cradle and provide smooth fading effects at switch on/off in order to keep baby sleeping.

![scheme](https://raw.githubusercontent.com/pawelcylo/arduino-night-light/master/scheme.png)

### Functionality description

The device is designed to emit soft light without any rapid blinks. It provides fading effects on every state change. Once it is switched on the light slowly appears and if button is pressed before the process is finished it smoothly goes into fade-out procedure. It allows to perform a quick peak into the babys cradle at night without fully lighting the area and waking up.

The light is turned on/off by pressing simple pushbutton.

Device is safely powered by a set of six AA batteries.

### Required components

- Arduino Uno Rev. 3 board (actually any older version should work as well).
- Light source that can be driven by PWM signal. I have used an existing USB LED light, simplest solution would be three LEDs 
connected in series via single resistor to limit the current (see [how to calculate the resistor value](http://electronics.stackexchange.com/questions/32990/do-i-really-need-resistors-when-controlling-leds-with-arduino)). Please note that the light source powered directly by Arduino output pin cannot exceed 40 mA power consumption. If it does it needs to be powered through transistor and external power source.
- 2-pin pushbutton that has a default state open.
- A set of wires to connect it all togeter. I have used male pins from breadboard wires cut in the middle and soldered into long wires.
- Safe power source for Arduino board (and for the light source if required). I have used a 6xAA battery mount. Remember to keep high voltage away from baby cradle!
