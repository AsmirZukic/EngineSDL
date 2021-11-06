#include "../include/engine.h"
#include "../include/inputHandler.hpp"
#include <iostream>

int main( int argc, char* argv[] )
{
  Engine engine;
  InputHandler handler;

  int countedFrames = 1;

  while( engine.isRunning() )
  {
    engine.render();
    handler.handleInput();
    engine.draw();

    float averageFPS = countedFrames/( Timer::getInstance()->getTicks() / 1000.f);

    if( averageFPS > 2000000 )
    {
      averageFPS = 0;
    }

    std::cout << averageFPS << " FPS \n";

    countedFrames++;
  }
}
