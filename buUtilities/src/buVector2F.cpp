#include "buVector2F.h"


namespace buEngineSDK {
  const buVector2F buVector2F::Zero = buVector2F(0.0f, 0.0f);

  buVector2F::buVector2F(float _x, float _y) : x(_x), y(_y) { }

  buVector2F::~buVector2F() { }

  buVector2F::buVector2F(const buVector2F& _v) : x(_v.x), y(_v.y) { }

  buVector2F& buVector2F::operator=(const buVector2F& _v)
  {
    x = _v.x;
    y = _v.y;
    return *this;
  }

  void buVector2F::operator+=(const buVector2F& _v)
  {
    x += _v.x;
    y += _v.y;
  }

  buVector2F buVector2F::operator+(const buVector2F& _v) const
  {
    return buVector2F(x + _v.x, y + _v.y);
  }

  void buVector2F::operator-=(const buVector2F& _v)
  {
    x -= _v.x;
    y -= _v.y;
  }

  buVector2F buVector2F::operator-(const buVector2F& _v) const
  {
    return buVector2F(x - _v.x, y - _v.y);
  }

  void buVector2F::operator*=(const float _a)
  {
    x *= _a;
    y *= _a;
  }

  buVector2F buVector2F::operator*(const float _a) const
  {
    return buVector2F(_a * x, _a * y);
  }

  void buVector2F::operator/=(const float _a)
  {
    x = x / _a;
    y = y / _a;
  }

  buVector2F buVector2F::operator/(const float _a) const
  {
    return buVector2F(x / _a, y / _a);
  }

  float buVector2F::dot(const buVector2F& _v) const
  {
    return x * _v.x + y * _v.y;
  }

  float buVector2F::operator*(const buVector2F& _v) const
  {
    return x * _v.x + y * _v.y;
  }

  buVector2F buVector2F::cross(const buVector2F& _v) const
  {
    return buVector2F(x * _v.y,
                      y * _v.x);
  }

  void buVector2F::operator%=(const buVector2F _v)
  {
    *this = cross(_v);
  }

  buVector2F buVector2F::operator%(const buVector2F& _v) const
  {
    return buVector2F(x * _v.y,
                      y * _v.x);
  }

  float buVector2F::mag()
  {
    float magnitude = std::sqrt(x * x + y * y);
    return magnitude;
  }

  void buVector2F::normalize()
  {
    float magnitude = std::sqrt(x * x + y * y);
    if (magnitude > 0.0f) {
      float oneOverMag = 1.0f / magnitude;
      x = x * oneOverMag;
      y = y * oneOverMag;
    }
  }



}