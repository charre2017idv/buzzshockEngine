/**
 * @file 
 * @version 
 * @date 00/00/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief 
 * @bug
 */
#define GTEST_HAS_TR1_TUPLE 0
#define GTEST_USE_OWN_TR1_TUPLE 0
#include <gtest/gtest.h>
#include<buPrerequisitesUtil.h>
#include "buVector2I.h"
#include "buVector2F.h"
#include "buVector3I.h"
#include "buVector3F.h"
using namespace buEngineSDK;
int 
main(int argc, char** argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


/** 
 * @brief 
 * @param 
 * @return 
 * @bug 
 */
TEST(buUtilities, Vector2I_Test)
{
 // ARRENGE - Vector normal initialization 
 buVector2I A(1, 2);
 // ARRENGE - Vector initialization from vector
 buVector2I initFromC(4, 5);
 buVector2I B(initFromC);
 // ARRENGE - General Vectors
 buVector2I vector1(3, 4);
 buVector2I vector2(6, 8);

 // ACT - Addition
 buVector2I C = vector1 + vector2;
 // ACT - Subtraction
 buVector2I D = vector1 - vector2;
 // ACT - Multiplication
 buVector2I E = vector1 * 5;
 // ACT - Division
 buVector2I F = vector2 / 2;
 // ACT - Vector Dot Product
 int32 dotProduct1 = vector1.dot(vector2);
 int32 dotProduct2 = vector1 * vector2;
 // ACT - Vector Cross Product
 buVector2I Vector1CrossVector2 = vector1.cross(vector2);
 // ACT - Vector magnitude
 int32 Magnitude = vector1.mag();
 // ACT - Vector normalized
 vector1.normalize();

 // ASSERT - Vector normal initialization 
 GTEST_ASSERT_EQ(A.x, 1);
 GTEST_ASSERT_EQ(A.y, 2);
 // ASSERT - Vector initialization from vector
 GTEST_ASSERT_EQ(B.x, 4);
 GTEST_ASSERT_EQ(B.y, 5);
 // ASSERT - Vector Addition
 GTEST_ASSERT_EQ(C.x, 9);
 GTEST_ASSERT_EQ(C.y, 12);
 // ASSERT - Vector subtraction
 GTEST_ASSERT_EQ(D.x, -3);
 GTEST_ASSERT_EQ(D.y, -4);
 // ASSERT - Vector Multiplication
 GTEST_ASSERT_EQ(E.x, 15);
 GTEST_ASSERT_EQ(E.y, 20);
 // ASSERT - Vector Division
 GTEST_ASSERT_EQ(F.x, 3);
 GTEST_ASSERT_EQ(F.y, 4);
 // ASSERT - Vector Dot Product
 GTEST_ASSERT_EQ(dotProduct1, 50);
 GTEST_ASSERT_EQ(dotProduct2, 50);
 // ASSERT - Vector Cross Product
 GTEST_ASSERT_EQ(Vector1CrossVector2.x, 24);
 GTEST_ASSERT_EQ(Vector1CrossVector2.y, 24);
 // ASSERT - Vector magnitude
 GTEST_ASSERT_EQ(Magnitude, 5);
 // ASSERT - Vector
 GTEST_ASSERT_EQ(vector1.x, 0);
 GTEST_ASSERT_EQ(vector1.y, 0);
}

/** 
 * @brief 
 * @param 
 * @return 
 * @bug 
 */
TEST(buUtilities, Vector2F_Test) {
 // ARRENGE - Vector normal initialization 
 buVector2F A(1.0f, 2.0f);
 // ARRENGE - Vector initialization from vector
 buVector2F initFromC(4.0f, 5.0f);
 buVector2F B(initFromC);
 // ARRENGE - General Vectors
 buVector2F vector1(3.0f, 4.0f);
 buVector2F vector2(6.0f, 8.0f);

 // ACT - Addition
 buVector2F C = vector1 + vector2;
 // ACT - Subtraction
 buVector2F D = vector1 - vector2;
 // ACT - Multiplication
 buVector2F E = vector1 * 5;
 // ACT - Division
 buVector2F F = vector2 / 2;
 // ACT - Vector Dot Product
 float dotProduct1 = vector1.dot(vector2);
 float dotProduct2 = vector1 * vector2;
 // ACT - Vector Cross Product
 buVector2F Vector1CrossVector2 = vector1.cross(vector2);
 // ACT - Vector magnitude
 float Magnitude = vector1.mag();
 // ACT - Vector normalized
 vector1.normalize();

 // ASSERT - Vector normal initialization 
 GTEST_ASSERT_EQ(A.x, 1.0f);
 GTEST_ASSERT_EQ(A.y, 2.0f);
 // ASSERT - Vector initialization from vector
 GTEST_ASSERT_EQ(B.x, 4.0f);
 GTEST_ASSERT_EQ(B.y, 5.0f);
 // ASSERT - Vector Addition
 GTEST_ASSERT_EQ(C.x, 9.0f);
 GTEST_ASSERT_EQ(C.y, 12.0f);
 // ASSERT - Vector subtraction
 GTEST_ASSERT_EQ(D.x, -3.0f);
 GTEST_ASSERT_EQ(D.y, -4.0f);
 // ASSERT - Vector Multiplication
 GTEST_ASSERT_EQ(E.x, 15.0f);
 GTEST_ASSERT_EQ(E.y, 20.0f);
 // ASSERT - Vector Division
 GTEST_ASSERT_EQ(F.x, 3.0f);
 GTEST_ASSERT_EQ(F.y, 4.0f);
 // ASSERT - Vector Dot Product
 GTEST_ASSERT_EQ(dotProduct1, 50.0f);
 GTEST_ASSERT_EQ(dotProduct2, 50.0f);
 // ASSERT - Vector Cross Product
 GTEST_ASSERT_EQ(Vector1CrossVector2.x, 24.0f);
 GTEST_ASSERT_EQ(Vector1CrossVector2.y, 24.0f);
 // ASSERT - Vector magnitude
 GTEST_ASSERT_EQ(Magnitude, 5.0f);
 // ASSERT - Vector
 GTEST_ASSERT_EQ(vector1.x, 0.6f);
 GTEST_ASSERT_EQ(vector1.y, 0.8f);
}

/** 
 * @brief 
 * @param 
 * @return 
 * @bug 
 */
TEST(buUtilities, Vector3I_Test) {
 // ARRENGE - Vector normal initialization 
 buVector3I A(1, 2, 3);
 // ARRENGE - Vector initialization from vector
 buVector3I initFromC(2, 3, 1);
 buVector3I B(initFromC);
 // ARRENGE - General Vectors
 buVector3I vector1(2, 3, 1);
 buVector3I vector2(1, 2, 0);

 // ACT - Addition
 buVector3I C = vector1 + vector2;
 // ACT - Subtraction
 buVector3I D = vector1 - vector2;
 // ACT - Multiplication
 buVector3I E = vector1 * 5;
 // ACT - Division
 buVector3I F = vector2 / 2;
 // ACT - Vector Dot Product
 int32 dotProduct1 = vector1.dot(vector2);
 int32 dotProduct2 = vector1 * vector2;
 // ACT - Vector Cross Product
 buVector3I Vector1CrossVector2 = vector1.cross(vector2);
 // ACT - Vector magnitude
 int32 Magnitude = vector1.mag();
 // ACT - Vector normalized
 vector1.normalize();

 // ASSERT - Vector normal initialization 
 GTEST_ASSERT_EQ(A.x, 1);
 GTEST_ASSERT_EQ(A.y, 2);
 GTEST_ASSERT_EQ(A.z, 3);
 // ASSERT - Vector initialization from vector
 GTEST_ASSERT_EQ(B.x, 2);
 GTEST_ASSERT_EQ(B.y, 3);
 GTEST_ASSERT_EQ(B.z, 1);
 // ASSERT - Vector Addition
 GTEST_ASSERT_EQ(C.x, 3);
 GTEST_ASSERT_EQ(C.y, 5);
 GTEST_ASSERT_EQ(C.z, 1);
 // ASSERT - Vector subtraction
 GTEST_ASSERT_EQ(D.x, 1);
 GTEST_ASSERT_EQ(D.y, 1);
 GTEST_ASSERT_EQ(D.z, 1);
 // ASSERT - Vector Multiplication
 GTEST_ASSERT_EQ(E.x, 10);
 GTEST_ASSERT_EQ(E.y, 15);
 GTEST_ASSERT_EQ(E.z, 5);
 // ASSERT - Vector Division
 GTEST_ASSERT_EQ(F.x, 0);
 GTEST_ASSERT_EQ(F.y, 1);
 GTEST_ASSERT_EQ(F.z, 0);
 // ASSERT - Vector Dot Product
 GTEST_ASSERT_EQ(dotProduct1, 8);
 GTEST_ASSERT_EQ(dotProduct2, 8);
 // ASSERT - Vector Cross Product
 GTEST_ASSERT_EQ(Vector1CrossVector2.x, -2);
 GTEST_ASSERT_EQ(Vector1CrossVector2.y, 1);
 GTEST_ASSERT_EQ(Vector1CrossVector2.z, 1);
 // ASSERT - Vector magnitude
 GTEST_ASSERT_EQ(Magnitude, 3);
 // ASSERT - Vector normalizado
 GTEST_ASSERT_EQ(vector1.x, 0);
 GTEST_ASSERT_EQ(vector1.y, 0);
 GTEST_ASSERT_EQ(vector1.z, 0);
}

/** 
 * @brief 
 * @param 
 * @return 
 * @bug 
 */
TEST(buUtilities, Vector3F_Test) {
  // ARRENGE - Vector normal initialization 
  buVector3F A(1.0f, 2.0f, 3.0f);
  // ARRENGE - Vector initialization from vector
  buVector3F initFromC(2.0f, 3.0f, 1.0f);
  buVector3F B(initFromC);
  // ARRENGE - General Vectors
  buVector3F vector1(2.0f, 3.0f, 1.0f);
  buVector3F vector2(1.0f, 2.0f, 0.0f);

  // ACT - Addition
  buVector3F C = vector1 + vector2;
  // ACT - Subtraction
  buVector3F D = vector1 - vector2;
  // ACT - Multiplication
  buVector3F E = vector1 * 5.0f;
  // ACT - Division
  buVector3F F = vector2 / 2;
  // ACT - Vector Dot Product
  float dotProduct1 = vector1.dot(vector2);
  float dotProduct2 = vector1 * vector2;
  // ACT - Vector Cross Product
  buVector3F Vector1CrossVector2 = vector1.cross(vector2);
  // ACT - Vector magnitude
  float Magnitude = vector1.mag();
  // ACT - Vector normalized
  vector1.normalize();

  // ASSERT - Vector normal initialization 
  GTEST_ASSERT_EQ(A.x, 1.0f);
  GTEST_ASSERT_EQ(A.y, 2.0f);
  GTEST_ASSERT_EQ(A.z, 3.0f);
  // ASSERT - Vector initialization from vector
  GTEST_ASSERT_EQ(B.x, 2.0f);
  GTEST_ASSERT_EQ(B.y, 3.0f);
  GTEST_ASSERT_EQ(B.z, 1.0f);
  // ASSERT - Vector Addition
  GTEST_ASSERT_EQ(C.x, 3.0f);
  GTEST_ASSERT_EQ(C.y, 5.0f);
  GTEST_ASSERT_EQ(C.z, 1.0f);
  // ASSERT - Vector subtraction
  GTEST_ASSERT_EQ(D.x, 1.0f);
  GTEST_ASSERT_EQ(D.y, 1.0f);
  GTEST_ASSERT_EQ(D.z, 1.0f);
  // ASSERT - Vector Multiplication
  GTEST_ASSERT_EQ(E.x, 10.0f);
  GTEST_ASSERT_EQ(E.y, 15.0f);
  GTEST_ASSERT_EQ(E.z, 5.0f);
  // ASSERT - Vector Division
  GTEST_ASSERT_EQ(F.x, 0.5f);
  GTEST_ASSERT_EQ(F.y, 1.0f);
  GTEST_ASSERT_EQ(F.z, 0.0f);
  // ASSERT - Vector Dot Product
  GTEST_ASSERT_EQ(dotProduct1, 8.0f);
  GTEST_ASSERT_EQ(dotProduct2, 8.0f);
  // ASSERT - Vector Cross Product
  GTEST_ASSERT_EQ(Vector1CrossVector2.x, -2.0f);
  GTEST_ASSERT_EQ(Vector1CrossVector2.y, 1.0f);
  GTEST_ASSERT_EQ(Vector1CrossVector2.z, 1.0f);
  // ASSERT - Vector magnitude
  float comparador = 3.74166;
  GTEST_ASSERT_EQ(Magnitude, comparador);
  // ASSERT - Vector normalizado
  //GTEST_ASSERT_EQ(vector1.x, 0.534522);
  //GTEST_ASSERT_EQ(vector1.y, 0);
  //GTEST_ASSERT_EQ(vector1.z, 0);
}
