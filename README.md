# Sonar
A sonar built with an Arduino.

## Components
+ Arduino MKR WiFi 1010 (That's the one I used but any should work)
+ Ultrasonic Sensor
+ Servo Motor
+ PC
+ USB cable
+ Jumper wires
+ A base to hold everything together
+ A piece to connect the Servo to the Ultrasonic Sensor

## Connections

| Ultrasound/ Servo: | Arduino: |
|--------------------|----------|
| Ultrasound Power   | 5V       |
| Ultrasound Ground  | GND      |
| Ultrasound Trigger | Pin 7    |
| Ultrasound Echo    | Pin 6    |
| Servo Power        | 5V       |
| Servo Ground       | GND      |
| Servo PWM          | Pin 5    |

## Files
There are 2 files in the repository:

+ Main.py: The computer side that handles the graphics of the sonar
+ sonar.ino: The arduino side that handles the actual sonar gathering data and moving the servo.

Note: The programs talk to each other using serial.

## Credits
By Matteo Giovanni
