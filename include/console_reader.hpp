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
   private:
      static ConsoleReader* instance;
      char currentReading;
      ConsoleReader();
      std::thread thread;
};

#endif // CONSOLEREADER_H