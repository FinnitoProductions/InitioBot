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
#include <input_devices.hpp>
#include <console_reader.hpp>


double maxDigitalOutput = 1;

Drivetrain* Drivetrain::instance = 0;

Drivetrain::Drivetrain() {
   leftMotors = {DigitalMotor(FORWARD_LEFT_DRIVE, REVERSE_LEFT_DRIVE, ENABLE_LEFT_DRIVE)};
   rightMotors = {DigitalMotor(FORWARD_RIGHT_DRIVE, REVERSE_RIGHT_DRIVE, ENABLE_RIGHT_DRIVE)};
}

void Drivetrain::periodic() {
   char x = ConsoleReader::getInstance()->getCurrentReading();

   bool wasInputUsed = ConsoleReader::getInstance()->getInputUsed();
   if (x == FORWARD_CHAR) {
      std::cout << "forward" << std::endl;
      leftOutput = 1;
      rightOutput = 1;
      ConsoleReader::getInstance()->setInputUsed(true);
   }
   else if (x == REVERSE_CHAR) {
      std::cout << "reverse" << std::endl;
      leftOutput = -1;
      rightOutput = -1;
      ConsoleReader::getInstance()->setInputUsed(true);
   }
   else if (x == LEFT_CHAR) {
      std::cout << "left" << std::endl;
      leftOutput = -1;
      rightOutput = 1;
      ConsoleReader::getInstance()->setInputUsed(true);
   }
   else if (x == RIGHT_CHAR) {
      std::cout << "right" << std::endl;
      leftOutput = 1;
      rightOutput = -1;
      ConsoleReader::getInstance()->setInputUsed(true);
   }
   else if (x == STOP_CHAR) {
      std::cout << "stop" << std::endl;
      leftOutput = 0;
      rightOutput = 0;
      ConsoleReader::getInstance()->setInputUsed(true);
   }
   else if (x == SLOW_DOWN_CHAR && !wasInputUsed) {
      std::cout << "slow down " << std::endl;
      maxDigitalOutput *= SLOW_DOWN_RATE;
      ConsoleReader::getInstance()->setInputUsed(true);
   }
   else if (x == SPEED_UP_CHAR && !wasInputUsed) {
      std::cout << "speed up" << std::endl;
      maxDigitalOutput = std::min(maxDigitalOutput / SLOW_DOWN_RATE, 1.0);
      ConsoleReader::getInstance()->setInputUsed(true);
   }

   // leftOutput = InputDevices::getInstance()->getLeftObstacleSensor().getTriggered(); 
   // rightOutput = InputDevices::getInstance()->getRightObstacleSensor().getTriggered();
   setBothOutputs(leftOutput * maxDigitalOutput, rightOutput * maxDigitalOutput);

   // std::cout << InputDevices::getInstance()->getLeftObstacleSensor().getTriggered() << ", " << InputDevices::getInstance()->getRightObstacleSensor().getTriggered() << std::endl;
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