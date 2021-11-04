#include "../include/engine.h"
#include "../include/inputHandler.hpp"

int main( int argc, char* argv[] )
{
  Engine engine;
  InputHandler handler;

  while( engine.isRunning() )
  {
    engine.render();
    handler.handleInput();
    engine.draw();
  }
}
