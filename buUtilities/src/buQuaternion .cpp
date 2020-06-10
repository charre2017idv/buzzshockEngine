#include "buQuaternion.h"

namespace buEngineSDK {
	buQuaternion::buQuaternion(float _s, buVector3F _v) : m_val(_s), m_axis(_v) { }

	buQuaternion::buQuaternion(const buQuaternion& _q)
	{
		m_val = _q.m_val;
		m_axis = _q.m_axis;
	}

	buQuaternion::~buQuaternion()
	{
	}

	buQuaternion& buQuaternion::operator=(const buQuaternion& _q)
	{
		m_val = _q.m_val;
		m_axis = _q.m_axis;

		return *this;
	}

	void buQuaternion::operator+=(const buQuaternion& _q)
	{
		m_val += _q.m_val;
		m_axis += _q.m_axis;
	}
	buQuaternion buQuaternion::operator+(const buQuaternion& _q) const
	{
		float value = m_val + _q.m_val;
		buVector3F imaginary = m_axis + _q.m_axis;

		return buQuaternion(value, imaginary);
	}

	void buQuaternion::operator-=(const buQuaternion& _q)
	{
		m_val -= _q.m_val;
		m_axis -= _q.m_axis;
	}

	buQuaternion buQuaternion::operator-(const buQuaternion& _q) const
	{
		float value = m_val - _q.m_val;
		buVector3F imaginary = m_axis - _q.m_axis;

		return buQuaternion(value, imaginary);
	}
	buQuaternion buQuaternion::multiply(const buQuaternion& _q) const
	{
		float  value = m_val * _q.m_val - m_axis.dot(_q.m_axis);
		buVector3F imaginary = _q.m_axis * m_val + m_axis * _q.m_val + m_axis.cross(_q.m_axis);
		return buQuaternion(value, imaginary);
	}
	void buQuaternion::operator*=(const buQuaternion& _q)
	{
		*this = multiply(_q);
	}
	buQuaternion buQuaternion::operator*(const buQuaternion& _q) const
	{
		float  value = m_val * _q.m_val - m_axis.dot(_q.m_axis);
		buVector3F imaginary = _q.m_axis * m_val + m_axis * _q.m_val + m_axis.cross(_q.m_axis);
		return buQuaternion(value, imaginary);
	}
	
	void buQuaternion::operator*=(const float value)
	{
		m_val *= value;
		m_axis *= value;
	}

	buQuaternion buQuaternion::operator*(const float value) const
	{
		float scalar = m_val * value;
		buVector3F imaginary = m_axis * value;
		return buQuaternion(scalar, imaginary);
	}
	
	float buQuaternion::mag()
	{
		float magnitude = buEngineSDK::buPlatformMath::sqrt
		(
			m_val * m_val + m_axis.x * m_axis.x + m_axis.y * m_axis.y + m_axis.z * m_axis.z
		);
		return magnitude;
	}
	void buQuaternion::normalize()
	{
		if (mag() != 0)
		{
			float normValue = 1 / mag();

			m_val *= normValue;
			m_axis *= normValue;
		}
	}
	buQuaternion buQuaternion::conjugate()
	{
		float scalar = m_val;
		buVector3F imaginary = m_axis * (-1);

		return buQuaternion(scalar, imaginary);
	}
	buQuaternion buQuaternion::inverse()
	{
		float absoluteValue = mag();
		absoluteValue *= absoluteValue;
		absoluteValue = 1 / absoluteValue;

		buQuaternion conjugateValue = conjugate();

		float scalar = conjugateValue.m_val * absoluteValue;
		buVector3F imaginary = conjugateValue.m_axis * absoluteValue;

		return buQuaternion(scalar, imaginary);
	}
}
