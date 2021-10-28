#include "../include/engine.h"

int main( int argc, char* argv[] )
{
  Engine engine;

  while( engine.isRunning() )
  {
    engine.handleInput();
    engine.render();
    engine.draw();
  }
}
