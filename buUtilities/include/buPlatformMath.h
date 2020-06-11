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
			return std::sqrtf(_v);
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

	};

}

