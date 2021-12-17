#include "../include/texture.hpp"
#include "../include/textureLoader.hpp"
#include "../include/renderer.hpp"

Texture::Texture( std::string path ) : mTexture( nullptr ), mWidht( 0 ), mHeight( 0 )
{
    mTexture = TextureLoader::getInstance()->loadTexture( path.c_str() );

    if( mTexture )
    {
        SDL_QueryTexture( mTexture, nullptr, nullptr, &mWidht, &mHeight);
    }
}

Texture::~Texture()
{
    free();
}

void Texture::free()
{
    if( mTexture )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = nullptr;
        mWidht = 0;
        mHeight = 0;
    }
}

void Texture::render( int xPos, int yPos )
{
    SDL_Rect renderQuad{ xPos, yPos, mWidht, mHeight };
    SDL_RenderCopy( Renderer::getInstance()->getRenderer(), mTexture, nullptr, &renderQuad );
}

void Texture::render( int xPos, int yPos, SDL_Rect* clip )
{
  SDL_Rect renderQuad{ xPos, yPos, mWidht, mHeight };

  if( clip )
  {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }

  SDL_RenderCopy( Renderer::getInstance()->getRenderer(), mTexture, clip, &renderQuad );
}
