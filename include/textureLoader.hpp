#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class TextureLoader
{
private: 
    static TextureLoader* instance;
    
    TextureLoader();
    TextureLoader( const TextureLoader& t2 );
    ~TextureLoader();
public: 
    SDL_Texture* loadTexture( std::string path );

    static TextureLoader* getInstance();
};