/**
* Defines methods for the servo turret on a robot.
*
* @author Finn Frankis
* @since 6/12/19
*/

#include <turret.hpp>
#include <robot_map.hpp>
#include <pigpio.h>
#include <console_reader.hpp>
#include <iostream>

Turret::Turret() : turretMotor(TURRET_SERVO), currentPosition(INITIAL_TURRET_POSITION_DEGREES) {
   gpioSetMode(TURRET_SERVO, PI_OUTPUT);
}

Turret* Turret::instance = 0;

Turret* Turret::getInstance() {
   if (instance == nullptr) {
      instance = new Turret();
   }

   return instance;
}

void Turret::periodic() {
   char input = ConsoleReader::getInstance()->getCurrentReading();

   bool wasInputUsed = ConsoleReader::getInstance()->getInputUsed();
   if (input == CLOCKWISE_CHAR && !wasInputUsed) {
      std::cout << "up" << std::endl;
      currentPosition += TURRET_DELTA_DEGREES_CLOCKWISE;
      ConsoleReader::getInstance()->setInputUsed(true);
   }
   else if (input == COUNTERCLOCKWISE_CHAR && !wasInputUsed) {
      std::cout << "down" << std::endl;
      currentPosition -= TURRET_DELTA_DEGREES_CLOCKWISE;
      ConsoleReader::getInstance()->setInputUsed(true);
   }

   turretMotor.setPosition(currentPosition);
}