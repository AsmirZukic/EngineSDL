#include "../include/window.hpp"
#include <iostream>
#include <stdexcept>

Window* Window::iWindow = nullptr;

Window::Window() = default;

Window::Window( int SCREEN_WIDTH, int SCREEN_HEIGHT )
{
  try
  {
    if( SDL_Init( SDL_INIT_VIDEO) < 0 )
    {
      throw SDL_GetError();
    }
    else
    {
      mWindow = SDL_CreateWindow( "Window class", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

      if( mWindow == nullptr )
      {
        throw SDL_GetError();
      }
        std::cout << "Window was created successfuly." << '\n';
    }
  } catch( const char* msg )
  {
    std::cerr << msg << "\n";
  }
}

void Window::close()
{
    SDL_DestroyWindow( mWindow );
    mWindow = nullptr;

    SDL_Quit();
}

Window::~Window()
{
  std::cout << "Window destructor was called" << '\n';

  close();
}


const bool Window::isOpen()
{
  return mWindow != nullptr;
}

SDL_Window* Window::getWindow()
{
  return mWindow;
}

Window* Window::getInstance()
{
    if( iWindow == nullptr )
    {
      iWindow = new Window( 640, 480 );
    }

    return iWindow;
}
