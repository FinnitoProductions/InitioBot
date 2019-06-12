/**
 * Represents a single PWM servo motor.
 * 
 * @author Finn Frankis
 * @since 6/12/19
*/

#ifndef SERVO_H
#define SERVO_H

class Servo {
   public:
      Servo(int gpio_pin);
      void setPosition(int posDegrees);
   private:
      int gpioPin;
      int MIN_VALUE_DEGREES = 0;
      int MAX_VALUE_DEGREES = 180;
      int MIN_VALUE_PULSE_WIDTH = 500;
      int MAX_VALUE_PULSE_WIDTH = 2500;
};

#endif // SERVO_H