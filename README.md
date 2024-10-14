# UltrasonicSensors
# Ultrasonic Sensors for River Cleaning Robot

This Arduino-based library is designed to manage multiple ultrasonic sensors and a servo for use in projects like a river-cleaning robot. It provides functions to measure water levels, detect obstacles, and locate garbage using ultrasonic sensors.

## Features
- **Water Level Detection**: Measure the water level in a tank or container.
- **Object Scanning**: Scan for objects or obstacles with a servo-based ultrasonic sensor.
- **Garbage Detection**: Detect the distance from static garbage or waste.

## Class: `UltrasonicSensors`

### Constructor
```cpp
UltrasonicSensors(int tankTrigPin, int tankEchoPin,
                  int garbTrigPin, int garbEchoPin,
                  int objectTrigPin, int objectEchoPin,
                  int servoPin);
