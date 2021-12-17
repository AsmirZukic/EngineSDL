#pragma once
#include <stdint.h>
#include <SDL2/SDL.h>
#include "vector2D.hpp"

enum mouse_buttons{ LEFT = 0, MIDDLE = 1, RIGHT = 2 };

class InputHandler
{
private:
  InputHandler();
  InputHandler( const InputHandler& h2 );
  ~InputHandler(){}

  static InputHandler* iHandler;

  // Keyboard //
  const uint8_t* keystates = SDL_GetKeyboardState( 0 );

  void onKeyDown(SDL_Event* event);
  void onKeyUp(SDL_Event* event);

  // Mouse //
  bool mouseButtonStates[3] = {0};

  Vector2D* mousePos;

  void onMouseMove(SDL_Event& e);
  void onMouseButtonDown(SDL_Event& e);
  void onMouseButtonUp(SDL_Event& e);

public:

	static InputHandler* getInstance();

	void update();

	// Keyboard //
	bool isKeyDown( SDL_Scancode key );

	// Mouse //
	bool getMouseButtonState(int buttonNum) { return mouseButtonStates[buttonNum]; }

	Vector2D* getMousePos() { return mousePos; }

	void reset();
};
