#include "buMatrix4x4.h"

namespace buEngineSDK {
	const buMatrix4x4 buMatrix4x4::Zero = buMatrix4x4(0.0f, 0.0f, 0.0f, 0.0f,
																										0.0f, 0.0f, 0.0f, 0.0f, 
																										0.0f, 0.0f, 0.0f, 0.0f, 
																										0.0f, 0.0f, 0.0f, 0.0f);

	const buMatrix4x4 buMatrix4x4::Identity = buMatrix4x4(1.0f, 0.0f, 0.0f, 0.0f,
																												0.0f, 1.0f, 0.0f, 0.0f,
																												0.0f, 0.0f, 1.0f, 0.0f,
																												0.0f, 0.0f, 0.0f, 1.0f);
	
	buMatrix4x4::buMatrix4x4(float x0, float y0, float z0, float w0, 
													 float x1, float y1, float z1, float w1, 
													 float x2, float y2, float z2, float w2, 
													 float x3, float y3, float z3, float w3) :
													 m_x0(x0), m_y0(y0), m_z0(z0), m_w0(w0),
													 m_x1(x1), m_y1(y1), m_z1(z1), m_w1(w1),
													 m_x2(x2), m_y2(y2), m_z2(z2), m_w2(w2),
													 m_x3(x3), m_y3(y3), m_z3(z3), m_w3(w3) { }

	buMatrix4x4::buMatrix4x4(buVector4F& Vx, buVector4F& Vy, 
													 buVector4F& Vz, buVector4F& Vw) :
		                       m_x0(Vx.x), m_y0(Vy.x), m_z0(Vz.x), m_w0(Vw.x),
		                       m_x1(Vx.y), m_y1(Vy.y), m_z1(Vz.y), m_w1(Vw.y),
		                       m_x2(Vx.z), m_y2(Vy.z), m_z2(Vz.z), m_w2(Vw.z),
		                       m_x3(Vx.w), m_y3(Vy.w), m_z3(Vz.w), m_w3(Vw.w) { }

	buMatrix4x4::buMatrix4x4(const buMatrix4x4& _mat) : 
		m_x0(_mat.m_x0), m_y0(_mat.m_y0), m_z0(_mat.m_z0), m_w0(_mat.m_w0),
		m_x1(_mat.m_x1), m_y1(_mat.m_y1), m_z1(_mat.m_z1), m_w1(_mat.m_w1),
		m_x2(_mat.m_x2), m_y2(_mat.m_y2), m_z2(_mat.m_z2), m_w2(_mat.m_w2),
		m_x3(_mat.m_x3), m_y3(_mat.m_y3), m_z3(_mat.m_z3), m_w3(_mat.m_w3) { }

	buMatrix4x4::~buMatrix4x4()
	{
	}
	
	float buMatrix4x4::det()
	{
		// Get the basic matrix
		buMatrix4x4 tmpMat = *this;
		// Set new vector for future initializations
		buVector4F v0(tmpMat.m_x0, tmpMat.m_y0, tmpMat.m_z0, tmpMat.m_w0);
		buVector4F v1(tmpMat.m_x1, tmpMat.m_y1, tmpMat.m_z1, tmpMat.m_w1);
		buVector4F v2(tmpMat.m_x2, tmpMat.m_y2, tmpMat.m_z2, tmpMat.m_w2); 
		buVector4F v3(tmpMat.m_x3, tmpMat.m_y3, tmpMat.m_z3, tmpMat.m_w3);
		// First Step - v3 -> v3 - pow(v2)
		buVector4F TwoV2 = v2 + v2;
		buVector4F newV3 = v3 - TwoV2;
		// Second Step - v2 <-> v1
		buMatrix4x4 tmpMat2(
			v0.x, v0.y, v0.z, v0.w,
			v1.x, v1.y, v1.z, v1.w,
			v2.x, v2.y, v2.z, v2.w,
			newV3.x, newV3.y, newV3.z, newV3.w);

		buVector4F V0(tmpMat2.m_x0, tmpMat2.m_y0, tmpMat2.m_z0, tmpMat2.m_w0);
		buVector4F V2(tmpMat2.m_x1, tmpMat2.m_y1, tmpMat2.m_z1, tmpMat2.m_w1);
		buVector4F V1(tmpMat2.m_x2, tmpMat2.m_y2, tmpMat2.m_z2, tmpMat2.m_w2);
		buVector4F V3(tmpMat2.m_x3, tmpMat2.m_y3, tmpMat2.m_z3, tmpMat2.m_w3);

		//buMatrix4x4 MatStep2(V0, V2, V1, V3);
		// Third Step - v2 -> v2 - pow3(v0)
		buVector4F ThreeV0 = (V0 + V0) + V0;
		buVector4F newV2 = V2 - ThreeV0;

		buMatrix4x4 tmpMatrix3(V0, V1, newV2, V3);


		//*this = tmpMatrix3;

		return (tmpMatrix3.m_x0 - tmpMatrix3.m_y1 - tmpMatrix3.m_z2 - tmpMatrix3.m_w3);
	}
}