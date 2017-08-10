#ifndef _POINT3D_H
#define _POINT3D_H

#include <inttypes.h>

namespace g3rb3n
{
  template <typename T>
  class Point3D
  {  
  public:
    T x;
    T y;
    T z;

    Point3D<T>(T x, T y, T z)
    {
      this->x = x;
      this->y = y;
      this->z = z;
    }

    template <typename O>
    Point3D<T>(const Point3D<O>& other)
    {
      this->x = other.x;
      this->y = other.y;
      this->z = other.z;
    }
    
    Point3D<T>& operator=(const Point3D<T>& other)
    {
      // check for self-assignment
      if(&other == this)
        return *this;
      this->x = other.x;
      this->y = other.y;
      this->z = other.z;
      return *this;
    }
    
    template <typename O>
    Point3D<T>& operator=(const Point3D<O>& other)
    {
      // check for self-assignment
      if(&other == (void*)this)
        return *this;
      this->x = other.x;
      this->y = other.y;
      this->z = other.z;
      return *this;
    }

    Point3D<T>& operator+=(const Point3D<T>& other)
    {
      this->x += other.x;
      this->y += other.y;
      this->z += other.z;
      return *this;
    }

    Point3D<T>& operator-=(const Point3D<T>& other)
    {
      this->x -= other.x;
      this->y -= other.y;
      this->z -= other.z;
      return *this;
    }

    Point3D<T>& operator*=(T other)
    {
      this->x *= other;
      this->y *= other;
      this->z *= other;
      return *this;
    }

    Point3D<T>& operator/=(T other)
    {
      this->x /= other;
      this->y /= other;
      this->z /= other;
      return *this;
    }
  };

}

#endif
