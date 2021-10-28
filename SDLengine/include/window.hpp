#pragma once

#include <SDL2/SDL.h>

class Window
{
private:

  SDL_Window* mWindow = nullptr;

  static Window* iWindow;

  Window();

  Window( int SCREEN_WIDTH, int SCREEN_HEIGHT );

  Window( const Window& );
public:

  ~Window();

  void close();

  const bool isOpen();

  SDL_Window* getWindow();

  static Window* getInstance();
};
