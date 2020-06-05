#pragma once
#include "buPrerequisitesUtil.h"
#include "buMath.h"

namespace buEngineSDK {
	class BU_UTILITY_EXPORT buVector4I
	{
	public:
		/**
		* @brief Default constructor for the class
		* @param
		* @return
		* @bug
		*/
		buVector4I();
		/**
		* @brief Constructor in charge of reciving two points for the vector.
		* @param
		* @return
		* @bug
		*/
		buVector4I(int32 _x, int32 _y, int32 _z, int32 _w);
		/**
		* @brief Destructor
		* @param
		* @return
		* @bug
		*/
		~buVector4I();
		/**
		* @brief Copy constructors
		* @param
		* @return
		* @bug
		*/
		buVector4I(const buVector4I& _v);
		/**
		* @brief Constructor to equal a vector
		* @param
		* @return
		* @bug
		*/
		buVector4I& 
		operator=(const buVector4I& _v);
		/**
		* @brief Method for addition of another vector
		* @param
		* @return
		* @bug
		*/
		void 
		operator+=(const buVector4I& _v);
		/**
		* @brief  Method that return a third vector representing the addition of
		* two 2D vectors
		* @param
		* @return
		* @bug
		*/
		buVector4I 
		operator+(const buVector4I& _v) const;
		/**
		* @brief Method for substract another vector
		* @param
		* @return
		* @bug
		*/
		void 
		operator-=(const buVector4I& _v);
		/**
		* @brief Method that return a third vector representing the substraction of
		* two 2D vectors
		* @param
		* @return
		* @bug
		*/
		buVector4I 
		operator-=(const buVector4I& _v) const;
		/**
		* @brief Method that multiply a vector with a scalar number
		* @param
		* @return
		* @bug
		*/
		void 
		operator*=(const int32 _a);
		/**
		* @brief Method that return a third vector representing the multiplication
		* of a vector with a scalar number.
		* @param
		* @return
		* @bug
		*/
		buVector4I 
		operator*=(const int32 _a) const;
		/**
		* @brief Method that devides a vector with a scalar number.
		* @param
		* @return
		* @bug
		*/
		void 
		operator/=(const int32 _a);
		/**
		* @brief Method that return a third vector representing the division of
		* a vector with a scalar number.
		* @param
		* @return
		* @bug
		*/
		buVector4I 
		operator/=(const int32 _a) const;
		/**
		* @brief Method that return a scalar from the multiplication of two vectors.
		* @param
		* @return
		* @bug
		*/
		int32 
		dot(const buVector4I& _v) const;
		/**
		* @brief Method that return a scalar from the multiplication of two vectors
		* directly.
		* @param
		* @return
		* @bug
		*/
		int32 
		operator*(const buVector4I& _v) const;
		/**
		* @brief Method that return a scalar from the current vector.
		* @param
		* @return
		* @bug
		*/
		int32 
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
		int32 x;

		/**
		 * @brief Member in charge of storing the point of the y - coordinate.
		 */
		int32 y;

		/**
		 * @brief Member in charge of storing the point of the z - coordinate.
		 */
		int32 z;
		
		/**
		 * @brief Member in charge of storing the point of the w - coordinate.
		 */
		int32 w;

		/**
		 * @brief Member in charge of giving an integer point with zero values.
		 */
		static const buVector4I Zero;
	};
}

