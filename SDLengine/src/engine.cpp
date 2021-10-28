#include "../include/engine.h"

Engine::Engine()
{
  if( window->getWindow() == nullptr )
  {
    printf("Window could not be created. \n" );
    running = false;
  }
  else
  {

    if( renderer->getRenderer() == nullptr )
    {
      printf("Renderer could not be created. \n" );
      running = false;
    }

    running = true;
    printf("Engine has been started successfuly \n" );
  }

}

Engine::~Engine()
{
  running = false;

  window->close();
  renderer->close();
}

void Engine::handleInput()
{
  SDL_Event event;

  while( SDL_PollEvent( &event ) != 0 )
  {
    if( event.type == SDL_QUIT )
    {
      window->close();
    }
  }
}

void Engine::render()
{
  SDL_SetRenderDrawColor( renderer->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF );

  SDL_RenderClear( renderer->getRenderer() );
}

const bool Engine::isRunning()
{
  return window->isOpen() && renderer->isCreated() && running;
}

void Engine::draw()
{
  SDL_RenderPresent( renderer->getRenderer() );
}
