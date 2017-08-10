#include <Arduino.h>
#include <unity.h>

#include "../src/Point3D.h"
#include "../src/Point3D_Math.h"

#ifdef UNIT_TEST

using namespace g3rb3n;

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

void testCastToInt(void) {
  Point3D<float> a = {1.1,2.2,3.3};
  Point3D<int> b = {1,2,3};
  Point3D<int> c = a;
  
  TEST_ASSERT_EQUAL(true, c == b);
}

void setup() {
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);

  UNITY_BEGIN();

  RUN_TEST(testMultiply);
  RUN_TEST(testDevide);
  RUN_TEST(testAdd);
  RUN_TEST(testSubtract);
  RUN_TEST(testCastToInt);
  
  UNITY_END();
}

void loop() {
}

#endif

