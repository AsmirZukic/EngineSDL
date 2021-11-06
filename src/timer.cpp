#include "../include/timer.hpp"
#include <SDL2/SDL.h>

Timer* Timer::iTimer = nullptr;

Timer::Timer()
{
  startTicks = 0;
  pausedTicks = 0;

  paused = false;
  started = false;
}

void Timer::start()
{
  started = true;

  paused = false;

  startTicks = SDL_GetTicks();
  pausedTicks = 0;
}

void Timer::stop()
{
  started = false;

  paused = false;

  startTicks = 0;

  pausedTicks = 0;
}

void Timer::pause()
{
  if( started && !paused )
  {
    paused = false;

    pausedTicks = SDL_GetTicks() - pausedTicks;

    startTicks = 0;
  }

}


void Timer::unpause()
{
  if( started && paused )
  {
    paused = false;

    startTicks = SDL_GetTicks() - pausedTicks;

    pausedTicks = 0;
  }
}

uint32_t Timer::getTicks()
{
  uint32_t time = 0;

  if( started )
  {
    if( paused )
    {
      time = pausedTicks;
    }
    else
    {
      time = SDL_GetTicks() - startTicks;
    }
  }

  return time;
}

bool Timer::isStarted()
{
  return started;
}

bool Timer::isPaused()
{
  return paused;
}

Timer* Timer::getInstance()
{
  if( !iTimer )
    iTimer = new Timer;

  return iTimer;
}
