#include "../include/textureLoader.hpp"
#include "../include/init.hpp"
#include "../include/renderer.hpp"
#include <stdexcept>
#include <iostream>

TextureLoader* TextureLoader::instance = nullptr;

TextureLoader::TextureLoader(){}

TextureLoader* TextureLoader::getInstance()
{
    if( !instance )
        instance = new TextureLoader();

    return instance;
}

SDL_Texture* TextureLoader::loadTexture( std::string path )
{
    SDL_Texture* newTexture = nullptr;

    try
    {
        if( !InitSDL_image() )
        {
            throw IMG_GetError();
        }
        else
        {
            SDL_Surface* loadedSurface = IMG_Load( path.c_str() );

            if( !loadedSurface )
            {
                throw SDL_GetError();
            }
            else
            {
                SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0x00, 0xFF, 0xFF ) );

                newTexture = SDL_CreateTextureFromSurface( Renderer::getInstance()->getRenderer(), loadedSurface );

                if( !newTexture )
                {
                    throw SDL_GetError();
                }

                SDL_FreeSurface( loadedSurface );
            }
        }
    } catch( const char* msg )
    {
        std::cerr << msg << "\n";
    }

    return newTexture;
}
