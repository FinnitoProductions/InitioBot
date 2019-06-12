/**
* Defines methods to detect input from an obstacle sensor where a signal of 1 means not triggered and a single of 0 means triggered.
*
* @author Finn Frankis
* @since 6/11/19
*/

#include <pigpio.h>
#include <obstacle_sensor.hpp>

ObstacleSensor::ObstacleSensor(int gpio_pin) : gpioPin(gpio_pin) {
   gpioSetMode(gpio_pin, PI_INPUT);
}

DigitalSensorState ObstacleSensor::getTriggered() {
   int currentValue = gpioRead(gpioPin);
   return currentValue == DigitalSensorState::TRIGGERED ? DigitalSensorState::TRIGGERED : DigitalSensorState::IDLE;
}