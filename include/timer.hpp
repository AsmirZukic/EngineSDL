#pragma once
#include <stdint.h>

class Timer
{
private:
  uint32_t startTicks;
  uint32_t pausedTicks;

  bool paused;
  bool started;

  static Timer* iTimer;

  Timer();
  Timer( const Timer& );

public:
  void start();
  void stop();
  void pause();
  void unpause();

  uint32_t getTicks();

  bool isStarted();
  bool isPaused();

  static Timer* getInstance();
};
