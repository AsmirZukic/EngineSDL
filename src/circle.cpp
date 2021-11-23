#include "../include/circle.hpp"
#include <stdint.h>
#include <math.h>


Circle::Circle( int xPos, int yPos, int radius ) : xPos( xPos ), yPos( yPos ) , radius( radius )
{
  computeBounds();
  update();
}

Circle::~Circle()
{
  texture = nullptr;
  SDL_DestroyTexture( texture );
}

void Circle::update()
{
  Uint32 rmask, gmask, bmask, amask;

  #if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
  #else
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
  #endif

  uint32_t pixelColor = 0xFFFFFFFF;

  //Create the texture that will store the image of our shape
  SDL_Surface* tempSurface = SDL_CreateRGBSurface( 0, boundingBox.w, boundingBox.h, 32, rmask, gmask, bmask, amask);
  texture = SDL_CreateTextureFromSurface( Renderer::getInstance()->getRenderer(), tempSurface );
  SDL_FreeSurface( tempSurface );

  //Allocate memory for a pixel buffer
  uint32_t* tempPixels = new uint32_t[ boundingBox.w * boundingBox.h * sizeof( uint32_t ) ];

  //Set all the bits inside the buffer to 0
  memset( tempPixels, 0, boundingBox.w * boundingBox.h * sizeof( uint32_t ) );

  //Draw the pixels
  for( int y = 0; y <= boundingBox.h / 2 ; ++y )
  {
    for( int x = 0; x <= boundingBox.w / 2 ; ++x )
    {
      int circleV = ( pow(x - boundingBox.x , 2) + pow( y - boundingBox.y , 2) ) - pow( radius, 2 );

      if( circleV <= 0 )
      {
        tempPixels[ ( y * boundingBox.w ) + x ] = pixelColor;
        tempPixels[ ( y * boundingBox.w )+ ( boundingBox.w - 1 ) - x ] = pixelColor;
        tempPixels[ ( ( ( boundingBox.h ) - y ) * boundingBox.w ) + x ] = pixelColor;
        tempPixels[ ( ( ( boundingBox.h ) - y ) * boundingBox.w ) + ( boundingBox.w - 1 ) - x ] = pixelColor;
      }
    }
  }

  SDL_UpdateTexture( texture, NULL, tempPixels, boundingBox.w * sizeof( uint32_t ) );

  delete[] tempPixels;

}


void Circle::render()
{
  //Source box
  SDL_Rect srcBox { 0, 0, boundingBox.w, boundingBox.h };

  SDL_RenderCopy( Renderer::getInstance()->getRenderer(), texture, &srcBox, &boundingBox );

}

void Circle::computeBounds()
{
  boundingBox.x = xPos - radius;
  boundingBox.y = yPos -  radius;
  boundingBox.w = radius * 2;
  boundingBox.h = radius * 2;
}
