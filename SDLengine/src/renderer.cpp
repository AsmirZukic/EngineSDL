#include "../include/renderer.hpp"
#include <iostream>
#include <stdexcept>

Renderer* Renderer::iRenderer = nullptr;

Renderer::Renderer()=default;

Renderer::Renderer( Window* window )
{
  try
  {
    //create the renderer
    mRenderer = SDL_CreateRenderer( window->getWindow() , -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

    //if the rendere was not created
    if( mRenderer == nullptr )
    {
      throw SDL_GetError();
    }
    else
    {
      //Set the render draw color to white
      SDL_SetRenderDrawColor( mRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

      std::cout << "Renderer created successfuly. \n";
    }
  }catch( const char* msg)
  {
    std::cerr << msg << '\n';
  }
}

Renderer::~Renderer()
{
  std::cout << "Renderer destructor called. \n";

  close();
}


const bool Renderer::isCreated()
{
  return mRenderer != nullptr;
}


void Renderer::close()
{
  SDL_DestroyRenderer( mRenderer );
  mRenderer = nullptr;

}

SDL_Renderer* Renderer::getRenderer()
{
  return mRenderer;
}


Renderer* Renderer::getInstance()
{
  if( iRenderer == nullptr )
  {
    iRenderer = new Renderer( Window::getInstance() );
  }

  return iRenderer;
}
