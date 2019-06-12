/**
* Defines methods for all the devices required for receiving user input.
* 
* @author Finn Frankis
* @since 6/7/19
*/

#include <input_devices.hpp>
#include <robot_map.hpp>
#include <iostream>
#include <math.h>

InputDevices* InputDevices::instance = 0;

InputDevices::InputDevices() : leftObstacleSensor(LEFT_OBSTACLE_SENSOR_INPUT), rightObstacleSensor(RIGHT_OBSTACLE_SENSOR_INPUT) {}

InputDevices* InputDevices::getInstance() {
   if (instance == nullptr) {
      instance = new InputDevices();
   }

   return instance;
}

ObstacleSensor InputDevices::getLeftObstacleSensor() { return leftObstacleSensor; }
ObstacleSensor InputDevices::getRightObstacleSensor() { return rightObstacleSensor; }