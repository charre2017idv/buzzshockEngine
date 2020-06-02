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

	private:
		

	};
}