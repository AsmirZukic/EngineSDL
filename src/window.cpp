#include "../include/window.hpp"
#include "../include/init.hpp"
#include <iostream>
#include <stdexcept>

Window* Window::iWindow = nullptr;

Window::Window() = default;

Window::Window( int SCREEN_WIDTH, int SCREEN_HEIGHT )
{
  try
  {
    if( !InitSDL() )
    {
      throw SDL_GetError();
    }
    else
    {
      mWindow = SDL_CreateWindow( "SDL Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE );

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
      iWindow = new Window( 1280, 720 );
    }
    //Else just return the singleton instance
    return iWindow;
}
