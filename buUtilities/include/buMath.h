#pragma once
#include "buPrerequisitesUtil.h"

namespace buEngineSDK {
	class buMath
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
	private:
		

	};
}