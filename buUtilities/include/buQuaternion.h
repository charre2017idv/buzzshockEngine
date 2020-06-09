/**
 * @file buQuaternion.h 
 * @version 1.0
 * @date 09/06/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief 
 * @bug None.
 */
#pragma once
#include "buPrerequisitesUtil.h"
#include "buVector3F.h"


namespace buEngineSDK {
	class BU_UTILITY_EXPORT buQuaternion
	{
	public:
		/**
		 * @brief Constructor 
		 */
		buQuaternion() = default;
		/**
		 * @brief Constructor 
		 */
		buQuaternion(float _s, buVector3F _v);
		/**
		 * @brief Copy Constructor 
		 */
		buQuaternion(const buQuaternion& _q);
		/**
		 * @brief Destructor
		 */
		~buQuaternion();
		/** 
		 * @brief Method that equals a quaternion 
		 * @param const buQuaternion& _q Quaternion
		 * @return Quaternion.
		 * @bug None.
		 */

		buQuaternion& 
		operator=(const buQuaternion& _q);
		/** 
		 * @brief Method in charge of adding another quaternion.
		 * @param const buQuaternion& _q Another Quaternion.
		 * @return None.
		 * @bug None.
		 */
		void
		operator+=(const buQuaternion& _q);
		/** 
		 * @brief Method that returns the result of the addition of two quaternions.
		 * @param const buQuaternion& _q Another Quaternion
		 * @return A quaternion.
		 * @bug None.
		 */
		buQuaternion 
		operator+(const buQuaternion& _q) const;
		/** 
		 * @brief Method in charge of subtract another quaternion.
		 * @param const buQuaternion& _q Another Quaternion.
		 * @return None.
		 * @bug None.
		 */
		void
		operator-=(const buQuaternion& _q);
		/** 
		* @brief Method that returns the result of the subtraction of two quaternions. 
		* @param const buQuaternion& _q Another Quaternion
		* @return A Quaternion.
		* @bug None.
		*/
		buQuaternion 
		operator-(const buQuaternion& _q) const;
	
	
	
	public:
		/**
		 * @brief Scalar constant value
		 */
		float m_val;
		/**
		 * @brief Vector that represents an axis.
		 */
		buVector3F m_axis;
	};
}