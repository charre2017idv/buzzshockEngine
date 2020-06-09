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
}
