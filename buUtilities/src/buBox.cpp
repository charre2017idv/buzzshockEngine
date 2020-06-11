#include "buBox.h"

namespace buEngineSDK {
	buBox::buBox(float _width, float _height, float _lenght)
	{
		m_width = _width;
		m_height = _height;
		m_length = _lenght;
	}

	buBox::buBox(const buVector3F& _v)
	{
		m_width = _v.x;
		m_height = _v.y;
		m_length = _v.z;
	}

	buBox::buBox(const buBox& _b)
	{
		m_width = _b.m_width;
		m_height = _b.m_height;
		m_length = _b.m_length;
	}
	
	buBox::~buBox()
	{
	}

	float buBox::getVolume()
	{
		return m_width * m_height * m_length;
	}
}