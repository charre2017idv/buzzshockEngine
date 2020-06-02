#include "buVector2I.h"

namespace buEngineSDK {
  const buVector2I buVector2I::Zero = buVector2I(0, 0);

  buVector2I::buVector2I() { }

  buVector2I::buVector2I(int32 _x, int32 _y) : x(_x), y(_y) { }

  buVector2I::~buVector2I() { }

  buVector2I::buVector2I(const buVector2I& _v) : x(_v.x), y(_v.y) { }

  buVector2I& buVector2I::operator=(const buVector2I& _v)
  {
    x = _v.x;
    y = _v.y;
    return *this;
  }

  void buVector2I::operator+=(const buVector2I& _v)
  {
    x += _v.x;
    y += _v.y;
  }

  buVector2I buVector2I::operator+(const buVector2I& _v) const
  {
    return buVector2I(x + _v.x, y + _v.y);
  }

  void buVector2I::operator-=(const buVector2I& _v)
  {
    x -= _v.x;
    y -= _v.y;
  }

  buVector2I buVector2I::operator-=(const buVector2I& _v) const
  {
    return buVector2I(x - _v.x, y - _v.y);
  }

  void buVector2I::operator*=(const int32 _a)
  {
    x *= _a;
    y *= _a;
  }

  buVector2I buVector2I::operator*=(const int32 _a) const
  {
    return buVector2I(_a*x,_a*y);
  }

  void buVector2I::operator/=(const int32 _a)
  {
    x = x / _a;
    y = y / _a;
  }

  buVector2I buVector2I::operator/=(const int32 _a) const
  {
    return buVector2I(x / _a, y / _a);
  }

  int32 buVector2I::dot(const buVector2I& _v) const
  {
    return x * _v.x + y * _v.y;
  }

  int32 buVector2I::operator*(const buVector2I& _v) const
  {
    return x * _v.x + y * _v.y;
  }

  buVector2I buVector2I::cross(const buVector2I& _v) const
  {
    return buVector2I( x * _v.y, 
                       y *_v.x );
  }

  void buVector2I::operator%=(const buVector2I _v)
  {
    *this = cross(_v);
  }

  buVector2I buVector2I::operator%(const buVector2I& _v) const
  {
    return buVector2I(x * _v.y,
                      y * _v.x);
  }

  int32 buVector2I::mag()
  {
    int32 magnitude = std::sqrt(x * x + y * y);
    return magnitude;
  }

  void buVector2I::normalize()
  {
    int32 magnitude = std::sqrt(x * x + y * y);
    if (magnitude>0.0f) {
      int32 oneOverMag = 1.0f / magnitude;
      x = x * oneOverMag;
      y = y * oneOverMag;
    }
  }



}