#ifndef _POINT3D_MATH_H
#define _POINT3D_MATH_H

#include <math.h>

#include "Point3D.h"

namespace g3rb3n
{
  template <typename T>
  Point3D<T> powPoint(T base, Point3D<T>& p)
  {
    Point3D<T> r;
    r.x = pow(base, p.x);
    r.y = pow(base, p.y);
    r.z = pow(base, p.z);
    return r;
  }
    
  template <typename T>
  Point3D<T> powPoint(Point3D<T>& b, Point3D<T>& p)
  {
    Point3D<T> r;
    r.x = pow(b.x, p.x);
    r.y = pow(b.y, p.y);
    r.z = pow(b.z, p.z);
    return r;
  }
    
  template <typename T>
  Point3D<T> roundPoint(Point3D<T>& p)
  {
    Point3D<T> r;
    r.x = round(p.x);
    r.y = round(p.y);
    r.z = round(p.z);
    return r;
  }
    
  template <typename T>
  Point3D<T> operator/(const Point3D<T>& p, T scale)
  {
    Point3D<T> r = p;
    r /= scale;
    return r;
  }

  template <typename T>
  Point3D<T> operator*(const Point3D<T>& p, T scale)
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
  Point3D<T> operator*(const Point3D<T>& a, const Point3D<T>& b)
  {
    Point3D<T> r = a;
    r *= b;
    return r;
  }

  template <typename T>
  Point3D<T> operator/(const Point3D<T>& a, const Point3D<T>& b)
  {
    Point3D<T> r = a;
    r /= b;
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
