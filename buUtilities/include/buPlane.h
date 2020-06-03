#pragma once
#include "buPrerequisitesUtil.h"
#include "buVector4F.h"
#include "buVector3F.h"


namespace buEngineSDK {
	class buPlane
	{
	public:
		/**
		* @brief Default constructor (no initialization)
		* @param None.
		* @return None.
		* @bug None.
		*/
		buPlane() = default;
		/**
		* @brief Constructor
		* @param V 4D vector to set up a plane.
		* @return None.
		* @bug None.
		*/
		buPlane(const buVector4F& V);
	  /**
	  * @brief Constructor
	  * @param X coefficient
	  * @param Y coefficient
	  * @param Z coefficient
	  * @param W coefficient
	  * @return None.
	  * @bug None.
	  */
		buPlane(float X, float Y, float Z, float W);
		/**
		* @brief Constructor
		* @param A First point in the plane.
		* @param B Second point in the plane.
		* @param C Third point in the plane.
		* @return None.
		* @bug None. 
		*/
		buPlane(const buVector3F& A, const buVector3F& B, const buVector3F& C);
		/**
		* @brief 
		* @param 
		* @return 
		* @bug 
		*/
		~buPlane();
		/**
		* @brief Calculates distance between plan and a point in the space.
		* @param V Represents the other point
		* @return A positive number if it is in front of the plane and 
		* a negative number if it is behind the plane.
		* @bug None.
		*/
		float
		planDot(const buVector3F& V) const;
		/**
		* @brief Method that returns a inverse plane.
		* @param None.
		* @return A flip plane.
		* @bug None.
		*/
		buPlane
	  flip() const;
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
	};
}
