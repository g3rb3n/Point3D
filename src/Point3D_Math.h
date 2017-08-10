#ifndef _POINT3D_MATH_H
#define _POINT3D_MATH_H

#include "Point3D.h"

namespace g3rb3n
{
  
  template <typename T>
  Point3D<T> operator/(const Point3D<T>& p, float scale)
  {
    Point3D<T> r = p;
    r /= scale;
    return r;
  }

  template <typename T>
  Point3D<T> operator*(const Point3D<T>& p, float scale)
  {
    Point3D<T> r = p;
    r *= scale;
    return r;
  }

  template <typename T>
  Point3D<T> operator+(const Point3D<T>& a, const Point3D<T>& b)
  {
    Point3D<T> r = a;
    r += b;
    return r;
  }

  template <typename T>
  Point3D<T> operator-(const Point3D<T>& a, const Point3D<T>& b)
  {
    Point3D<T> r = a;
    r -= b;
    return r;
  }

  template <typename T>
  bool operator==(const Point3D<T>& a, const Point3D<T>& b)
  {
    return
      a.x == b.x &&
      a.y == b.y &&
      a.z == b.z;
  }

}

#endif
