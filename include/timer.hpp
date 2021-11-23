#pragma once
#include <stdint.h>

class Timer
{
private:
  uint32_t startTicks;
  uint32_t pausedTicks;

  bool paused;
  bool started;

public:
  Timer();
  Timer( const Timer& t2 );

  void start();
  void stop();
  void pause();
  void unpause();

  uint32_t getTicks();

  bool isStarted();
  bool isPaused();

};
