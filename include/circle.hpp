#pragma once
#include "engine.h"

class Circle
{
private:

  SDL_Rect boundingBox;
  int  xPos, yPos, radius;
  SDL_Texture* texture = nullptr;
public:
  
  Circle( int xPos, int yPos, int radius );
  ~Circle();

  void render();
  void update();
  void computeBounds();
};
