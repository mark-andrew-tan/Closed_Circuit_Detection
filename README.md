# Detect Closed Circuit

### Project Goal
Build a device that will activate (blink LED) when a button has been pressed for a certain amount of time (acts as button debounce)

### Hardware 
- Arduino UNO

### Design

- delay() function could not be used as the code needs to constantly be checking for an input.
- millis() funcion was used as the global timer that would blink the LED, and hold the time that the button has been closed to begin the LED blinking
- Used the built in Arduino LED

![GitHub Dark](https://github.com/mark-andrew-tan/Closed_Circuit_Detection/blob/main/Schematic%20(Source%20-%20Arduino.cc).png)
(Source: Arduino.cc)
