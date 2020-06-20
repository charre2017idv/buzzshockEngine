/**
 * @file buPlatformMath.h
 * @version 1.0
 * @date 01/06/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief Class in charge of setting the basic mathematic
 * @bugs None.
 */
#pragma once
#include "buPrerequisitesUtil.h"

namespace buEngineSDK {
  class buPlatformMath
  {
  public:
   /**
    * @brief Method that return the sqrt value from the std library.
    * @param Value
    * @return sqrt float value.
    * @bug None.
    */
   static float
   sqrt(float _v) {
   	return std::sqrt(_v);
   }

   /**
    * @brief Method that return the sqr from the buEngine.
    * @param _v Value of the constant.
    * @return A sqr value.
    */
   static FORCEINLINE float
     sqr(float _v) {
     return _v * _v;
   }

   /**
    * @brief Method that return the sqrtf value from the std library.
    * @param Value
    * @return sqrtf float value.
    * @bug None.
    */
   static float
   sqrtf(float _v) {
   	return std::sqrtf(_v);
   }

   /** 
    * @brief Method that return the inverse sqrt fromt the buEngine.
    * @param _v Value of the constant.
    * @return A inverse sqrt value.
    */
   static float 
   invSqrt(float _v) {
     return 1.0f / sqrt(_v);
   }

   /**
    * @brief Method that return the pow value from the std library.
    * @param float _x Constant.
    * @param float _y Constant.
    * @return pow float value.
    * @bug None.
    */
   static float 
   pow(float _x, float _y) {
   	return std::pow(_x, _y);
   }

   /**
    * @brief Method that return the powf value from the std library.
    * @param float _x Constant.
    * @param float _y Constant.
    * @return powf float value.
    * @bug None.
    */
   static float 
   powf(float _x, float _y) {
   	return std::powf(_x, _y);
   }

   /**
    * @brief Method that return the cos value from the std lib.
    * @param float _v scalar value.
    * @return cos value.
    * @bug None.
    */
   static float
   cos(float _v) {
   	return std::cos(_v);
   }

   /**
    * @brief Method that return the sin value from the std lib.
    * @param float _v scalar value.
    * @return sin value.
    * @bug None.
    */
   static float
   sin(float _v) {
   	return std::sin(_v);
   }

   /**
    * @brief Method that return the tan value from the std lib.
    * @param float _v scalar value.
    * @return tan value.
    * @bug None.
    */
   static float
   tan(float _v) {
   	return std::tan(_v);
   }

   /**
    * @brief Method that return the cons float value from the std lib.
    * @param float _v scalar value.
    * @return cosf value.
    * @bug None.
    */
   static float
   cosf(float _v) {
   	return std::cosf(_v);
   }

   /**
    * @brief Method that return the sin float value from the std lib.
    * @param float _v scalar value.
    * @return sinf value.
    * @bug None.
    */
   static float
   sinf(float _v) {
   	return std::sinf(_v);
   }

   /**
    * @brief Method that return the tan float value from the std lib.
    * @param float _v scalar value.
    * @return tanf value.
    * @bug None.
    */
   static float 
   tanf(float _v) {
    return std::tanf(_v);
   }

   /** 
    * @brief Method that return a factorial value.
    * @param _v scalar value.
    * @return A factorial.
    */
   static int
   factorial(int _v) {
     int32 F = 1;
     for (int i = 1; i <= _v; ++i) {
       F = F * i;
     }
     return F;
   }

   /** 
    * @brief Method in charge of getting the value a Maclaurin series.
    * @param _number Number of terms.
    * @param _angle Angle value.
    * @return A sin value.
    */
   static double 
   sinTaylor(int _number, float _angle) {
     double sin = 0;

     for (int k = 0; k < _number; k++) {
       sin = sin + pow(-1, k) * pow(_angle, 2 * k + 1) / factorial(2 * k + 1);
     }
     return sin;
   }

   /**
    * @brief Method in charge of getting the value a Maclaurin series.
    * @param _number Number of terms.
    * @param _angle Angle value.
    * @return A cos value.
    */
   static double 
   cosTaylor(int _number, float _angle) {
     double cos = 0;

     for (int k = 0; k < _number; k++) {
       cos = cos + pow(-1, k) * pow(_angle, 2 * k) / factorial(2 * k);
     }
     return cos;
   }
  
  };
}
