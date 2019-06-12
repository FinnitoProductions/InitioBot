/**
* Defines methods for the drivetrain on a robot, with a set of motors on each side.
*
* @author Finn Frankis
* @version 6/2/19
*/

#include <drivetrain.hpp>
#include <iostream>
#include <algorithm>
#include <robot_map.hpp>


double maxDigitalOutput = 1;

Drivetrain* Drivetrain::instance = 0;

Drivetrain::Drivetrain() {
   leftMotors = {DigitalMotor(FORWARD_LEFT_DRIVE, REVERSE_LEFT_DRIVE, ENABLE_LEFT_DRIVE)};
   rightMotors = {DigitalMotor(FORWARD_RIGHT_DRIVE, REVERSE_RIGHT_DRIVE, ENABLE_RIGHT_DRIVE)};
}

void Drivetrain::periodic() {
   char x;
   std::cin >> x;

   if (x == FORWARD_CHAR) {
      std::cout << "forward" << std::endl;
      leftOutput = 1;
      rightOutput = 1;
   }
   else if (x == REVERSE_CHAR) {
      std::cout << "reverse" << std::endl;
      leftOutput = -1;
      rightOutput = -1;
   }
   else if (x == LEFT_CHAR) {
      std::cout << "left" << std::endl;
      leftOutput = -1;
      rightOutput = 1;
   }
   else if (x == RIGHT_CHAR) {
      std::cout << "right" << std::endl;
      leftOutput = 1;
      rightOutput = -1;
   }
   else if (x == STOP_CHAR) {
      std::cout << "stop" << std::endl;
      leftOutput = 0;
      rightOutput = 0;
   }
   else if (x == SLOW_DOWN_CHAR) {
      std::cout << "slow down " << std::endl;
      maxDigitalOutput *= SLOW_DOWN_RATE;
   }
   else if (x == SPEED_UP_CHAR) {
      std::cout << "speed up" << std::endl;
      maxDigitalOutput = std::min(maxDigitalOutput / SLOW_DOWN_RATE, 1.0);
   }
   setBothOutputs(leftOutput * maxDigitalOutput, rightOutput * maxDigitalOutput);
}

void Drivetrain::setBothOutputs (double left_output, double right_output) {
   for (DigitalMotor m : leftMotors) {
      m.setOutput(left_output);
   }
   for (DigitalMotor m : rightMotors) {
      m.setOutput(right_output);
   }
}

Drivetrain* Drivetrain::getInstance() {
   if (instance == nullptr) {
      instance = new Drivetrain();
   }

   return instance;
}

std::vector<DigitalMotor> Drivetrain::getLeftMotors() { return leftMotors; }     
std::vector<DigitalMotor> Drivetrain::getRightMotors() { return rightMotors; }