/**
* Represents the servo arm on a robot.
*
* @author Finn Frankis
* @since 6/12/19
*/

#ifndef ARM_H
#define ARM_H

#include <subsystem.hpp>
#include <servo.hpp>

static const char UP_CHAR = 'i';
static const char DOWN_CHAR = 'k';
static const double ARM_DELTA_DEGREES_UP = -10; // the amount of degrees which the servo moves up for each increment
static const int INITIAL_ARM_POSITION_DEGREES = 90;

class Arm : public Subsystem {
   public:
      void periodic();
      static Arm* getInstance();
   private:
      Servo armMotor;
      static Arm* instance;
      int currentPosition;
      char prevInput;
      Arm();
};

#endif // SERVO_H