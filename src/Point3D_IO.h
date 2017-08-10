#ifndef _POINT3D_OUT_H
#define _POINT3D_OUT_H

#include "Point3D.h"
#if !defined(ESP8266)

#include <iostream>

namespace g3rb3n
{
  template <typename T>
  std::ostream& operator<<(std::ostream& o, const Point3D<T>& p)
  {
    o << '(' << p.x << ',' << p.y << ',' << p.z << ')';
    return o;
  }

}

#endif //defined(ESP8266)
#endif //_POINT3D_OUT_H
