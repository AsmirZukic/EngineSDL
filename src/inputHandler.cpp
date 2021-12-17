#include "../include/inputHandler.hpp"
#include "../include/engine.hpp"

InputHandler* InputHandler::iHandler = nullptr;

InputHandler::InputHandler() : mousePos( new Vector2D(0, 0) ) {}

void InputHandler::update()
{
	SDL_Event event;

	while ( SDL_PollEvent( &event ) )
	{
		switch ( event.type )
		{
		case SDL_QUIT:
			Window::getInstance()->close();
			break;

		case SDL_KEYDOWN:
			onKeyDown( &event );
			break;

		case SDL_KEYUP:
			onKeyUp( &event );
			break;

		case SDL_MOUSEMOTION:
			onMouseMove( event );
			break;

		case SDL_MOUSEBUTTONDOWN:
				onMouseButtonDown( event );
			break;

		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp( event );
			break;

		default:
			break;
		}
	}
}

void InputHandler::onMouseButtonDown( SDL_Event& e )
{

	if ( e.button.button == SDL_BUTTON_LEFT )
	{
		mouseButtonStates[LEFT] = true;
	}
  else if ( e.button.button == SDL_BUTTON_MIDDLE )
	{
		mouseButtonStates[MIDDLE] = true;
	}
  else if ( e.button.button == SDL_BUTTON_RIGHT )
	{
		mouseButtonStates[RIGHT] = true;
	}
}

void InputHandler::onMouseButtonUp( SDL_Event& e )
{
	if ( e.button.button == SDL_BUTTON_LEFT )
	{
		mouseButtonStates[LEFT] = false;
	}
  else if ( e.button.button == SDL_BUTTON_MIDDLE )
	{
		mouseButtonStates[MIDDLE] = false;
	}
  else if ( e.button.button == SDL_BUTTON_RIGHT )
	{
		mouseButtonStates[RIGHT] = false;
	}
}

void InputHandler::onMouseMove( SDL_Event& e )
{
	mousePos->setX( e.motion.x );
	mousePos->setY( e.motion.y );
}

void InputHandler::reset()
{
	for (int i = 0; i < 3; i++)
	{
		mouseButtonStates[i] = false;
	}
}

void InputHandler::onKeyDown( SDL_Event* event )
{

}

void InputHandler::onKeyUp(SDL_Event* event)
{

}

bool InputHandler::isKeyDown( SDL_Scancode key )
{
	if ( keystates != 0 )
	{
		if ( keystates[key] == 1 )
			return true;
		else
			return false;
	}
	return false;
}

InputHandler* InputHandler::getInstance()
{
  if ( !iHandler )
    iHandler = new InputHandler();

  return iHandler;
}
