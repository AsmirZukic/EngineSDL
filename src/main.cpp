#include "../include/engine.hpp"
#include "../include/texture.hpp"

int main( int argc, char* argv[] )
{
  while( Engine::getInstance()->isRunning() )
  {
    Engine::getInstance()->render();
    Engine::getInstance()->draw();
  }
}
