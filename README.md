# UltrasonicSensors

# Project Overview
This project involves the development of a river-cleaning robot that autonomously scan and detect waste in water bodies. The robot is equipped with multiple ultrasonic sensors for different tasks:

# Water level detection: Monitors the level of water in a container or tank.
# Obstacle detection: Scans the surroundings to detect objects and avoid obstacles.
# Garbage detection: Detects waste or garbage in the water, helping in efficient cleaning.
The ultrasonic sensors are controlled by a single class, which simplifies sensor management and data collection for the robot's operations.
# Ultrasonic Sensors for River Cleaning Robot

This Arduino-based library is designed to manage multiple ultrasonic sensors and a servo for use in projects like a river-cleaning robot. It provides functions to measure water levels, detect obstacles, and locate garbage using ultrasonic sensors.

## Features
- **Water Level Detection**: Measure the garbage level in a tank or container.
- **Object Scanning**: Scan for objects or obstacles with a servo-based ultrasonic sensor.
- **Garbage Detection**: Detect the distance from static garbage or waste.

## Class: `UltrasonicSensors`

### Constructor
```cpp
UltrasonicSensors(int tankTrigPin, int tankEchoPin,
                  int garbTrigPin, int garbEchoPin,
                  int objectTrigPin, int objectEchoPin,
                  int servoPin);
