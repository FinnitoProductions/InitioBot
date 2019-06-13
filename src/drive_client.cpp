/**
* The client file containing the main() method to execute all robot operations.
* 
* @author Finn Frankis
* @version 6/1/19
*/

#include <pigpio.h>
#include <iostream>
#include <digital_motor.hpp>
#include <robot_map.hpp>
#include <scheduler.hpp>
#include <chrono>
#include <thread>
#include <math.h>
#include <drivetrain.hpp>
#include <arm.hpp>
#include <console_reader.hpp>

int main() {
   gpioInitialise(); // must be called in any pigpio program before interfacing with GPIO
   std::cout << "GPIO initialized." << std::endl;

   Drivetrain* d = Drivetrain::getInstance();
   Arm* a = Arm::getInstance();

   gpioSetMode(18, PI_OUTPUT);
   gpioSetMode(13, PI_OUTPUT);
   gpioSetMode(19, PI_INPUT);
   gpioSetMode(26, PI_INPUT);

   while (true) {
      Scheduler::getInstance()->run();
      std::this_thread::sleep_for(std::chrono::milliseconds(5));

      // int x;
      // std::cin >> x;

      // gpioServo(18, x);
      // gpioServo(13, x);
      // std::cout << gpioRead(19) << ", " << gpioRead(26) << std::endl;
   }

   
   gpioTerminate();
}