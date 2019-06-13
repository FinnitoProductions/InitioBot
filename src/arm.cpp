/**
* Defines methods for the servo arm on a robot.
*
* @author Finn Frankis
* @since 6/12/19
*/

#include <arm.hpp>
#include <robot_map.hpp>
#include <pigpio.h>
#include <console_reader.hpp>
#include <iostream>

Arm::Arm() : armMotor(ARM_SERVO), currentPosition(INITIAL_ARM_POSITION_DEGREES) {
   gpioSetMode(ARM_SERVO, PI_OUTPUT);
}

Arm* Arm::instance = 0;

Arm* Arm::getInstance() {
   if (instance == nullptr) {
      instance = new Arm();
   }

   return instance;
}

void Arm::periodic() {
   char input = ConsoleReader::getInstance()->getCurrentReading();

   bool wasInputUsed = ConsoleReader::getInstance()->getInputUsed();
   if (input == UP_CHAR && !wasInputUsed) {
      std::cout << "up" << std::endl;
      currentPosition += ARM_DELTA_DEGREES_UP;
      ConsoleReader::getInstance()->setInputUsed(true);
   }
   else if (input == DOWN_CHAR && !wasInputUsed) {
      std::cout << "down" << std::endl;
      currentPosition -= ARM_DELTA_DEGREES_UP;
      ConsoleReader::getInstance()->setInputUsed(true);
   }

   armMotor.setPosition(currentPosition);
}