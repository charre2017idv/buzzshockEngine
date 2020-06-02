#pragma once
#include "buPrerequisitesUtil.h"
#include "buMath.h"

namespace buEngineSDK {
	class buVector4F
	{
	public:
		/**
		* @brief Default constructor for the class
		* @param
		* @return
		* @bug
		*/
		buVector4F();
		/**
		* @brief Constructor in charge of reciving two points for the vector.
		* @param
		* @return
		* @bug
		*/
		buVector4F(float _x, float _y, float _z, float _w);
		/**
		* @brief Destructor
		* @param
		* @return
		* @bug
		*/
		~buVector4F();
		/**
		* @brief Copy constructors
		* @param
		* @return
		* @bug
		*/
		buVector4F(const buVector4F& _v);
		/**
		* @brief Constructor to equal a vector
		* @param
		* @return
		* @bug
		*/
		buVector4F& 
		operator=(const buVector4F& _v);
		/**
		* @brief Method for addition of another vector
		* @param
		* @return
		* @bug
		*/
		void 
		operator+=(const buVector4F& _v);
		/**
		* @brief  Method that return a third vector representing the addition of
		* two 2D vectors
		* @param
		* @return
		* @bug
		*/
		buVector4F 
		operator+(const buVector4F& _v) const;
		/**
		* @brief Method for substract another vector
		* @param
		* @return
		* @bug
		*/
		void 
		operator-=(const buVector4F& _v);
		/**
		* @brief Method that return a third vector representing the substraction of
		* two 2D vectors
		* @param
		* @return
		* @bug
		*/
		buVector4F 
		operator-=(const buVector4F& _v) const;
		/**
		* @brief Method that multiply a vector with a scalar number
		* @param
		* @return
		* @bug
		*/
		void 
		operator*=(const float _a);
		/**
		* @brief Method that return a third vector representing the multiplication
		* of a vector with a scalar number.
		* @param
		* @return
		* @bug
		*/
		buVector4F 
		operator*=(const float _a) const;
		/**
		* @brief Method that devides a vector with a scalar number.
		* @param
		* @return
		* @bug
		*/
		void 
		operator/=(const float _a);
		/**
		* @brief Method that return a third vector representing the division of
		* a vector with a scalar number.
		* @param
		* @return
		* @bug
		*/
		buVector4F 
		operator/=(const float _a) const;
		/**
		* @brief Method that return a scalar from the multiplication of two vectors.
		* @param
		* @return
		* @bug
		*/
		float
		dot(const buVector4F& _v) const;
		/**
		* @brief Method that return a scalar from the multiplication of two vectors
		* directly.
		* @param
		* @return
		* @bug
		*/
		float
		operator*(const buVector4F& _v) const;
		/**
		* @brief Method that return a scalar from the current vector.
		* @param
		* @return
		* @bug
		*/
		float 
		mag();
		/**
		* @brief Method that normalize the current vector.
		* @param
		* @return
		* @bug
		*/
		void 
		normalize();


	private:

	public:
		/**
		 * @brief Member in charge of storing the point of the x - coordinate.
		 */
		float x;

		/**
		 * @brief Member in charge of storing the point of the y - coordinate.
		 */
		float y;

		/**
		 * @brief Member in charge of storing the point of the z - coordinate.
		 */
		float z;

		/**
		 * @brief Member in charge of storing the point of the w - coordinate.
		 */
		float w;

		/**
		 * @brief Member in charge of giving an integer point with zero values.
		 */
		static const buVector4F Zero;
	};
}
