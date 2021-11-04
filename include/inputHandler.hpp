#pragma once
#include <vector>
#include "window.hpp"

class InputHandler
{
private:
  bool mousePressed = false;
  std::vector<SDL_Event>& GetFrameEvents();
public:
  InputHandler();
  void handleInput();
  bool isMousePressed();

};
