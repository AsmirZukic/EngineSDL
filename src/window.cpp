#include "../include/window.hpp"
#include <iostream>
#include <stdexcept>

Window* Window::iWindow = nullptr;
int Window::SCREEN_WIDTH = 1280;
int Window::SCREEN_HEIGHT = 750;

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
      mWindow = SDL_CreateWindow( "SDL Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

      //If the created window is equal to nullptr
      if( !mWindow )
        throw SDL_GetError();
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
  close();
}

//Singleton getter
Window* Window::getInstance()
{
    //If the instance of window is not nullptr
    if( !iWindow )
    {
      //Create a new instance of window
      iWindow = new Window( SCREEN_WIDTH, SCREEN_HEIGHT );
    }
    //Else just return the singleton instance
    return iWindow;
}


const int Window::getWindowWidth()
{
  return SCREEN_WIDTH;
}

const int Window::getWindowHeigt()
{
  return SCREEN_HEIGHT;
}
