/**
* Represents the drivetrain on a robot, with a set of motors on each side.
*
* @author Finn Frankis
* @since 6/2/19
*/

#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <subsystem.hpp>
#include <vector>
#include <digital_motor.hpp>

static const char FORWARD_CHAR = 'w';
static const char REVERSE_CHAR = 's';
static const char LEFT_CHAR = 'a';
static const char RIGHT_CHAR = 'd';
static const char SLOW_DOWN_CHAR = 'l';
static const char SPEED_UP_CHAR = 'u';
static const char STOP_CHAR = 'o';

static const double SLOW_DOWN_RATE = 0.8;

extern double maxDigitalOutput; // the maximum output percent when the motors are being enabled as on/off

class Drivetrain : public Subsystem {
   public:
      void periodic();
      void setBothOutputs (double left_output, double right_output);
      static Drivetrain* getInstance();
      std::vector<DigitalMotor> getLeftMotors();
      std::vector<DigitalMotor> getRightMotors();
   private:
      std::vector<DigitalMotor> leftMotors;
      std::vector<DigitalMotor> rightMotors;
      double leftOutput;
      double rightOutput;
      static Drivetrain* instance;
      Drivetrain();
};

#endif // DRIVETRAIN_H