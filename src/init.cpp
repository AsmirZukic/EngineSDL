#include "../include/init.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

bool InitSDL()
{
    if( SDL_INIT_VIDEO < 0 )
        return false;
    else 
        return true;
}

bool InitSDL_image()
{
    int imgFlags = IMG_INIT_PNG;

    if( !( IMG_Init( imgFlags) & imgFlags ) )
    {
        return false;
    }
    else 
        return true;
}