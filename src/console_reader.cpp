/**
* Defines methods which use multithreading to read in values periodically from the console.
*
* @author Finn Frankis
* @since 6/12/19
*/ 

#include <console_reader.hpp>
#include <iostream>
#include <thread>

ConsoleReader* ConsoleReader::instance = 0;

ConsoleReader::ConsoleReader() : wasInputUsed(false), thread([]() {
      while(true) {
         char input;
         std::cin >> input;
         ConsoleReader::getInstance()->setCurrentReading(input);
      }
   }) {}

ConsoleReader* ConsoleReader::getInstance() {
   if (instance == nullptr) {
      instance = new ConsoleReader();
   }

   return instance;
}

char ConsoleReader::getCurrentReading() {
   return currentReading;
}

void ConsoleReader::setCurrentReading(char new_reading) {
   currentReading = new_reading;
   wasInputUsed = false;
}

bool ConsoleReader::getInputUsed() {
   return wasInputUsed;
}

void ConsoleReader::setInputUsed(bool new_input_used) {
   wasInputUsed = new_input_used;
}