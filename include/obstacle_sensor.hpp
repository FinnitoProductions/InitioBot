/**
* Detects input from an obstacle sensor where a signal of 1 means not triggered and a single of 0 means triggered.
*
* @author Finn Frankis
* @since 6/11/19
*/

#ifndef OBSTACLESENSOR_H
#define OBSTACLESENSOR_H

enum DigitalSensorState { TRIGGERED = 0, IDLE = 1 };

class ObstacleSensor {
   public:
      DigitalSensorState getTriggered();
      ObstacleSensor(int gpio_pin);
   private:
      int gpioPin;
};

#endif // OBSTACLESENSOR_H