/**
* @file buPlatformMath.h
* @version 1.0
* @date 01/06/2020
* @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
* @brief Class in charge of setting the basic 
* @bugs
*/
#pragma once
#include "buPrerequisitesUtil.h"

namespace buEngineSDK {
	class buPlatformMath
	{
	public:
		buPlatformMath();
		~buPlatformMath();

		/**
		 * @brief Add method template
		 */
		template<typename T>
		T Add(const T A, const T B) {
			return (A + B);
		}

		/**
		 * @brief Sub method template
		 */
		template<typename T>
		T Sub(const T A, const T B) {
			return (A - B);
		}

		/**
		 * @brief Multiply method template
		 */
		template<typename T>
		T Mul(const T A, const T B) {
			return (A * B);
		}

		/**
		 * @brief Division method template
		 */
		template<typename T>
		T Div(const T A, const T B) {
			return (A / B);
		}

	};

}

