/**
* Uses multithreading to read in values periodically from the console.
*
* @author Finn Frankis
* @since 6/12/19
*/ 

#ifndef CONSOLEREADER_H
#define CONSOLEREADER_H

#include <thread>

class ConsoleReader {
   public:
      static ConsoleReader* getInstance();
      char getCurrentReading();
      void setCurrentReading(char new_reading);
      bool getInputUsed();
      void setInputUsed(bool new_input_used);
      std::thread thread;
   private:
      static ConsoleReader* instance;
      char currentReading;
      ConsoleReader();
      bool wasInputUsed; // whether or not the most recent input has been used
};

#endif // CONSOLEREADER_H