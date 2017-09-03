#include <Arduino.h>

#include "../../../src/Point3D.h"
#include "../../../src/Point3D_Math.h"
#include "../../../src/Point3D_Print.h"

using namespace g3rb3n;

void add(float* p)
{
  p[0] += 2;
  p[1] += 2;
  p[2] += 2;  
}

void add(Point3D<float>& p)
{
  p += 2;
}

void testPerformance()
{
  uint32_t runs = 100000;
  float v[3] = {1,1,1};
  long start, duration1, duration2;

  start = micros();
  for (uint32_t i = 0 ; i < runs ; ++i)
  {
    add(v);
  }
  duration1 = micros() - start;
  Serial.print("Using floats  ");
  Serial.print(Point3D<float>(v));
  Serial.println(duration1);

  Point3D<float> p(1,1,1);
  start = micros();
  for (uint32_t i = 0 ; i < runs ; ++i)
  {
    add(p);
  }
  duration2 = micros() - start;
  Serial.print("Using Point3D ");
  Serial.print(p);
  Serial.println(duration2);
}


void setup() 
{
  Serial.begin(230400);
  Serial.println();
}

void loop() 
{
  testPerformance();
}


