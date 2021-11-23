#include "../include/engine.h"

int main( int argc, char* argv[] )
{
  while( Engine::getInstance()->isRunning() )
  {
    Engine::getInstance()->render();
    Engine::getInstance()->draw();
  }
}
