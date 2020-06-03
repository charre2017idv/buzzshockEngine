#pragma once
#include "buPrerequisitesUtil.h"

namespace buEngineSDK {

	/**
		 * @brief
		 */
	template<class T>
	T
		abs(const T A) {
		return (A >= (T)0) ? A : -A;
	}

	template<>
	float
		abs<float>(const float A) {
		return static_cast<float>(std::fabsf(A));
	}

	class buMath
	{
	public:
		buMath();
		~buMath();

		/**
		* @brief Method that returns an pow value from the std function
		* @param Base
		* @param Exponent
		* @return float value from std function
		* @bug None
		*/
		static float
		pow(float Base, float Exponent) {
			return std::powf(Base, Exponent);
		}
	
		/**
		* @brief Function that return a exp float value from the std function
		* @param Value
		* @return float value from the std function
		* @bug None
		*/
		static float
		exp(float Value) {
			return std::expf(Value);
		}
		/**
		* @brief Method that return a float log from the std function
		* @param Value
		* @return Float value from the std function
		* @bug None
		*/
		static float
		logE(float Value) {
			return std::logf(Value);
		}
		/**
		* @brief Method that return a float value from the std float log 
		* and the normal log float
		* @param Value
		* @return A float value from the float log division with the normal std log
		* @bug None
		*/
		static float
		log2(float Value) {
			return std::logf(Value) / std::log(2.0f);
		}
		 /**
		 * @brief Method that return a float from the division of a x value 
		 * and a base value.
		 * @param Base
		 * @param Value
		 * @return A float value from the division of log value and log base.
		 * @bug None.
		 */
		static float
		logX(float Base, float Value) {
			return logE(Value) / logE(Base);
		}
		/**
		* @brief Method that return the sqrt value from the std library.
		* @param Value
		* @return sqrt float value.
		* @bug None.
		*/
		static float
		sqrt(float Value) {
			return std::sqrtf(Value);
		}

		/*static Radian
			sqrt(const Radian& Value) {
			return Radian(sqrt(Value.valueRadians()));
		}

		static Degree
			sqrt(const Degree& Value) {
			return Degree(sqrt(Value.valueDegrees()));
		}*/

		/**
		* @brief Method that return a sqrt function divided upper one.
		* @param F
		* @return A division with sqrt value upper one.
		* @bug None.
		*/
		static float
		invSqrt(float F) {
			return 1.0f / std::sqrtf(F);
		}
		/**
		* @brief Method that return a cos value from the std library.
		* @param Value
		* @return A cos result from the standar library.
		* @bug None.
		*/
		static float
		cos(float Value) {
			return std::cosf(Value);
		}
		/**
		* @brief Method that return a sin value from the std library.
		* @param Value
		* @return A sin result from the standar library.
		* @bug None.
		*/
		static float
		sin(float Value) {
			return std::sin(Value);
		}
		/**
		* @brief Method that return a tan value from the std library.
		* @param Value
		* @return A tan result from the standar library.
		* @bug None.
		*/
		static float
		tan(float Value) {
			return std::tanf(Value);
		}
		/**
		* @brief Method that return the square of a value.
		* @param A that is a constant.
		* @return The square of a value
		* @bug None.
		*/
		template<class T>
		static T
		square(const T A) {
			return A * A;
		}
		/**
		* @brief Method that retruns the lowest between two values.
		* @param A first value of the range.
		* @param B second value of the range.
		* @return Retruns the lowest between two values.
		* @bug None.
		*/
		template<class T>
		static T
		min(const T A, const T B) {
			return (A <= B) ? A : B;
		}
		/**
		* @brief Method that retruns the highest between two values.
		* @param A first value of the range.
		* @param B second value of the range.
		* @return Retruns the lowest between two values.
		* @bug None.
		*/
		template<class T>
		static T
		max(const T A, const T B) {
			return (A >= B) ? A : B;
		}
		/**
		* @brief Method that retruns the lowest between three values.
		* @param A first value of the range.
		* @param B second value of the range.
		* @param C third value of the range.
		* @return Retruns the lowest between three values.
		* @bug None.
		*/
		template<class T>
		static T
		min3(const T A, const T B, const T C) {
			return min(min(A, B), C);
		}
		/**
		* @brief Method that retruns the highest between three values.
		* @param A first value of the range.
		* @param B second value of the range.
		* @param C third value of the range.
		* @return Retruns the lowest between three values.
		* @bug None.
		*/
		template<class T>
		static T
		max3(const T A, const T B, const T C) {
			return max(max(A, B), C);
		}
		/**
		* @brief Method that clamp a value within an inclusive range.
		* @param X value for the clamping
		* @param Min value to analize
		* @param Max value to analize
		* @return A value within an inclusive range.
		* @bug None.
		*/
		template<class T>
		static T
		clamp(const T X, const T Min, const T Max) {
			return X < Min ? Min : X < Max ? X : Max;
		}
		/**
		* @brief Method that return the absolute of value.
		* @param A value.
		* @return Return the absolute of value.
		* @bug None. 
		*/
		template<class T>
		static T
		abs(const T A) {
			return geEngineSDK::abs<T>(A);
		}


	private:
		

	};
}