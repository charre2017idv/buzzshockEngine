/**
 * @file buMatrix4x4.h
 * @version 1.0
 * @date 07/06/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief Class in charge of providing a matrix 4x4 for the math lib, 
 * this matrix works as column major, and get inspiration from this 
 * video: https://www.youtube.com/watch?v=4HMU9IKtOcw
 * @bugs None.
 */
#pragma once
#include "buVector4F.h"

namespace buEngineSDK {
	class BU_UTILITY_EXPORT buMatrix4x4
	{
	public:
		/**
		 * @brief Default Constructor
		 */
		buMatrix4x4() = default;
		/**
		 * @brief Constructor
		 */
		buMatrix4x4(float x0, float y0, float z0, float w0,
								float x1, float y1, float z1, float w1,
								float x2, float y2, float z2, float w2,
								float x3, float y3, float z3, float w3);
		/**
		 * @brief Vector initalization Contructor
		 */
		buMatrix4x4(buVector4F& Vx, 
								buVector4F& Vy,
								buVector4F& Vz,
								buVector4F& Vw);
		/**
		 * @brief Copy constructor
		 */
		buMatrix4x4(const buMatrix4x4& _mat);

		/**
		 * @brief Destructor
		 */
		~buMatrix4x4();
		
		 /**
		 * @brief 
		 * @param 
		 * @return 
		 * @bug 
		 */
		float 
		det();

	public:
		/**
		 * @brief Constant values for the X column.
		 */
		float m_x0, m_x1, m_x2, m_x3;
		/**
		 * @brief Constant values for the Y column.
		 */
		float m_y0, m_y1, m_y2, m_y3;
		/**
		 * @brief Constant values for the Z column.
		 */
		float m_z0, m_z1, m_z2, m_z3;
		/**
		 * @brief Constant values for the W column.
		 */
		float m_w0, m_w1, m_w2, m_w3;
		/**
		 * @brief Member in charge of giving an integer point with zero values.
		 */
		static const buMatrix4x4 Zero;
		/**
		 * @brief Member in charge of setting a Identity matrix
		 */
		static const buMatrix4x4 Identity;
	};

}