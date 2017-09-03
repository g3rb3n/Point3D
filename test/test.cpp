#include <Arduino.h>
#include <unity.h>

#include "../src/Point3D.h"
#include "../src/Point3D_Math.h"
#include "../src/Point3D_Print.h"

#ifdef UNIT_TEST

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
  float v[3];
  long start, duration1, duration2;

  start = micros();
  for (uint16_t i = 0 ; i < 10000 ; ++i)
  {
    add(v);
  }
  duration1 = micros() - start;

  Point3D<float> p;
  start = micros();
  for (uint16_t i = 0 ; i < 10000 ; ++i)
  {
    add(p);
  }
  duration2 = micros() - start;
  float diff = static_cast<float>(duration1 - duration2) / duration1;
  TEST_ASSERT_FLOAT_WITHIN(.02, 0., diff);
}

void testMultiply(void) {
  Point3D<int> a = {1,2,3};
  Point3D<int> b = {3,6,9};
  
  TEST_ASSERT_EQUAL(true, a * 3 == b);
}

void testDevide(void) {
  Point3D<int> a = {1,2,3};
  Point3D<int> b = {3,6,9};
  
  TEST_ASSERT_EQUAL(true, b / 3 == a);
}

void testAdd(void) {
  Point3D<int> a = {1,2,3};
  Point3D<int> b = {2,4,6};
  Point3D<int> c = {3,6,9};
  
  TEST_ASSERT_EQUAL(true, a + b == c);
}

void testSubtract(void) {
  Point3D<int> a = {1,2,3};
  Point3D<int> b = {2,4,6};
  Point3D<int> c = {3,6,9};
  
  TEST_ASSERT_EQUAL(true, c - b == a);
}

void testPow(void) {
  float base = 2;
  Point3D<float> a = {1,2,3};
  Point3D<float> e = {2,4,8};
  Point3D<float> p;
  p = powPoint(base, a);
  p = roundPoint(p);
  
  TEST_ASSERT_EQUAL(true, p == e);
}

void testCastToInt(void) {
  Point3D<float> a = {1.1,2.2,3.3};
  Point3D<int> b = {1,2,3};
  Point3D<int> c = a;
  
  TEST_ASSERT_EQUAL(true, c == b);
}

void testCastToUInt16(void) {
  Point3D<float> a = {1.1,2.2,3.3};
  Point3D<uint16_t> b = {1,2,3};
  Point3D<uint16_t> c = a;
  
  TEST_ASSERT_EQUAL(true, c == b);
}

void testTypeConversion()
{
  Point3D<float> i = {1.1,2.2,3.3};
  Point3D<int16_t> r = i;
  Point3D<int16_t> e = {1,2,3};

  TEST_ASSERT_EQUAL(true, e == r);
}

void setup() {
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);
  pow(2.0, 3.0);
  UNITY_BEGIN();

  RUN_TEST(testMultiply);
  RUN_TEST(testDevide);
  RUN_TEST(testAdd);
  RUN_TEST(testSubtract);
  RUN_TEST(testCastToInt);
  RUN_TEST(testCastToUInt16);
  RUN_TEST(testPow);
  RUN_TEST(testTypeConversion);
  RUN_TEST(testPerformance);
  
  UNITY_END();
}

void loop() {
}

#endif

