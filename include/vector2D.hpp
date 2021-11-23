#pragma once
#include <math.h>

class Vector2D
{
public:
  Vector2D( double X, double Y) : mX( X ), mY( Y ) {}

  double getX() { return mX; }
  double getY() { return mY; }

  void setX( double X ) { mX = X; }
  void setY( double Y ) { mY = Y; }

  double lenght() { return sqrt( mX * mX + mY * mY ); }

  Vector2D operator+( const Vector2D& v2 ) const
  {
    return Vector2D( mX + v2.mX, mY + v2.mY );
  }

  friend Vector2D& operator +=( Vector2D& v1, const Vector2D& v2)
  {
    v1.mX += v2.mX;
    v1.mY += v2.mY;

    return v1;
  }

  Vector2D operator*( double scalar )
  {
    return Vector2D( mX * scalar, mY * scalar );
  }

  Vector2D& operator*=( double scalar )
  {
    mX *= scalar;
    mY *= scalar;

    return *this;
  }

  Vector2D operator-( const Vector2D& v2 ) const
  {
     return Vector2D( mX - v2.mX, mY - v2.mY );
  }

  friend Vector2D& operator-=( Vector2D& v1, const Vector2D& v2 )
  {
     v1.mX -= v2.mX;
     v1.mY -= v2.mY;

     return v1;
   }

   Vector2D operator/( double scalar )
   {
     return Vector2D(mX / scalar, mY / scalar);
   }

   Vector2D& operator/=(double scalar)
   {
     mX /= scalar;
     mY /= scalar;

     return *this;
   }

   void normalise()
   {
     double l = lenght();

     if( l > 0 )
     {
       ( *this ) *= 1 / 1;
     }
   }

 private:
   double mX, mY;
};
