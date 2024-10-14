#ifndef ULTRASONICSENSORS_H
#define ULTRASONICSENSORS_H
#include <Arduino.h>
#include <Servo.h>

class UltrasonicSensors {
public:
    UltrasonicSensors(int tankTrigPin, int tankEchoPin,
                      int garbTrigPin, int garbEchoPin,
                      int objectTrigPin, int objectEchoPin,
                      int servoPin);
    void sensorsInit();
    unsigned int getTankLevel(int tankHeight); // Measure water level
    unsigned int scanForObject(int threshold); // Measure distance while scanning with servo
    unsigned int getGarbDistance(); // Measure distance from static object sensor

private:
    int _tankTrigPin;
    int _tankEchoPin;
    int _objectTrigPin;
    int _objectEchoPin;
    int _garbTrigPin;
    int _garbEchoPin;
    int _servoPin;
    Servo servo;
    unsigned int getDistance(uint8_t trigPin, uint8_t echoPin);
};

#endif