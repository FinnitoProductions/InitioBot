/**
* Stores all the devices required for receiving user input.
* 
* @author Finn Frankis
* @since 6/7/19
*/

#ifndef INPUTDEVICES_H
#define INPUTDEVICES_H

#include <robot_map.hpp>
#include <obstacle_sensor.hpp>

class InputDevices {
   private:
      const int LEFT_OBSTACLE_SENSOR_INPUT = 15;
      const int RIGHT_OBSTACLE_SENSOR_INPUT = 23;

      static InputDevices* instance;
      InputDevices();
      ObstacleSensor leftObstacleSensor;
      ObstacleSensor rightObstacleSensor;
   public:
      static InputDevices* getInstance();
      ObstacleSensor getLeftObstacleSensor();
      ObstacleSensor getRightObstacleSensor();
};

#endif // INPUTDEVICES_H