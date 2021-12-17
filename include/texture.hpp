#pragma once

#include <SDL2/SDL.h>
#include <string>

class Texture
{
private:
    SDL_Texture* mTexture;
    int mWidht, mHeight;

public:
    Texture(){}
    Texture( std::string path );
    ~Texture();

    void render( int xPos, int yPos);
    void render( int xPos, int yPos, SDL_Rect* clip );
    void free();

    const int getWidth() { return mWidht; }
    const int getHeight() { return mHeight; }
};
