#include <Arduino.h>
#include "UltrasonicSensors.h"

// Constructor
UltrasonicSensors::UltrasonicSensors(int tankTrigPin, int tankEchoPin,
                                     int garbTrigPin, int garbEchoPin,
                                     int objectTrigPin, int objectEchoPin,
                                     int servoPin) {
    _tankTrigPin = tankTrigPin;
    _tankEchoPin = tankEchoPin;
    _garbTrigPin = garbTrigPin;
    _garbEchoPin = garbEchoPin;
    _objectTrigPin = objectTrigPin;
    _objectEchoPin = objectEchoPin;
    _servoPin = servoPin;
}

// Initialize sensors
void UltrasonicSensors::sensorsInit() {
    pinMode(_tankTrigPin, OUTPUT);
    pinMode(_tankEchoPin, INPUT);
    pinMode(_objectTrigPin, OUTPUT);
    pinMode(_objectEchoPin, INPUT);
    pinMode(_garbTrigPin, OUTPUT);
    pinMode(_garbEchoPin, INPUT);
    servo.attach(_servoPin);
    servo.write(90); // Set to default position
}

// Get distance from ultrasonic sensor
unsigned int UltrasonicSensors::getDistance(uint8_t trigPin, uint8_t echoPin) {
    int distance = 0;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    unsigned long duration = pulseIn(echoPin, HIGH);
    distance = duration / 58;
    return distance;
}

// Measure water level in tank
unsigned int UltrasonicSensors::getTankLevel(int tankHeight) {
    unsigned int distance = getDistance(_tankTrigPin, _tankEchoPin);
    unsigned int wasteLevel = tankHeight - distance;
    unsigned int tankLevel = (wasteLevel * 100) / tankHeight; // Return percentage as integer
    return tankLevel;
}

// Scan for object within a threshold distance
unsigned int UltrasonicSensors::scanForObject(int threshold) {
    int angle, detectedAngle = 0;
    for (angle = 0; angle < 180; angle += 5) {
        servo.write(angle);
        unsigned int distance = getDistance(_objectTrigPin, _objectEchoPin);
        delay(150);
        if (distance < threshold) {
            detectedAngle = angle;
            break;
        }
    }
    servo.write(90);
    return detectedAngle;
}

// Measure distance to garbage
unsigned int UltrasonicSensors::getGarbDistance() {
    unsigned int distance = getDistance(_garbTrigPin, _garbEchoPin);
    // if(distance < /* threshold */) {
    //     // turn On relays
    // } else {
    //     // turn Off relays
    // }
    return distance;
}