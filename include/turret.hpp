/**
* Represents the servo turret on a robot.
*
* @author Finn Frankis
* @since 6/12/19
*/

#ifndef TURRET_H
#define TURRET_H

#include <subsystem.hpp>
#include <servo.hpp>

static const char CLOCKWISE_CHAR = 'l';
static const char COUNTERCLOCKWISE_CHAR = 'j';
static const double TURRET_DELTA_DEGREES_CLOCKWISE = 10; // the amount of degrees which the servo moves up for each increment
static const int INITIAL_TURRET_POSITION_DEGREES = 90;

class Turret : public Subsystem {
   public:
      void periodic();
      static Turret* getInstance();
   private:
      Servo turretMotor;
      static Turret* instance;
      int currentPosition;
      char prevInput;
      Turret();
};

#endif // TURRET_H