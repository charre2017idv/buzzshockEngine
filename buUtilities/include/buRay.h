/**
 * @file 
 * @version 
 * @date 00/00/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief 
 * @bug
 */
#pragma once
#include "buPrerequisitesUtil.h"
#include "buVector3F.h"

namespace buEngineSDK {
	class buRay
	{
	public:
		/**
		 * @brief Default constructor 
		 */
		buRay() = default;
		/**
		 * @brief Constructor 
		 */



		~buRay();

	private:
		/**
		 * @brief Is the distance from the origin of the point.
		 */
		float m_distance;
		/**
		 * @brief Ray origin
		 */
		buVector3F m_origin;
		/**
		 * @brief Ray direction (Neet to be normalized)
		 */
		buVector3F m_direction;
	};
}
