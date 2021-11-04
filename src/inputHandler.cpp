#include "../include/inputHandler.hpp"
#include <iostream>

InputHandler::InputHandler()
{
  GetFrameEvents();
}

std::vector<SDL_Event>& InputHandler::GetFrameEvents()
{
  static std::vector<SDL_Event> frame_events;
  return frame_events;
}

void InputHandler::handleInput()
{
  SDL_Event event;

  while( SDL_PollEvent( &event ) != 0 )
  {
    GetFrameEvents().push_back(event);
  }

  for( auto &it : GetFrameEvents() )
  {
    switch( it.type )
    {
      case SDL_QUIT:
        Window::getInstance()->close();
        break;

      case SDL_MOUSEBUTTONDOWN:
        std::cout<< "Mouse button was pressed\n";
        mousePressed = true;
        break;

      case SDL_MOUSEBUTTONUP:
      std::cout<< "Mouse button was released\n";
        mousePressed = false;
        break;
    }
  }

  GetFrameEvents().clear();
}

bool InputHandler::isMousePressed()
{
  return mousePressed;
}
