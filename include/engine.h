#pragma once
#include "renderer.hpp"
#include "inputHandler.hpp"

class Engine
{
private:
  bool running = false;

  static Engine* iEngine;

  Engine();
  Engine( const Engine& e2 );

  ~Engine();

public:
  static Engine* getInstance();

  virtual void render();

  const bool isRunning();

  void draw();
};
