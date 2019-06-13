/**
 * Represents a single PWM servo motor.
 * 
 * @author Finn Frankis
 * @since 6/12/19
*/

#include <pigpio.h>
#include <servo.hpp>
#include <utilities.hpp>
#include <iostream>

Servo::Servo(int gpio_pin) : gpioPin(gpio_pin) {
   gpioSetMode(gpio_pin, PI_OUTPUT);
}

void Servo::setPosition(int posDegrees) {
   gpioServo(gpioPin, Utilities::map(posDegrees, MIN_VALUE_DEGREES, MAX_VALUE_DEGREES, MIN_VALUE_PULSE_WIDTH, MAX_VALUE_PULSE_WIDTH));
}