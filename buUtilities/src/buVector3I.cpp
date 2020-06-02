
#include "buVector3I.h"
namespace buEngineSDK {
  const buVector3I buVector3I::Zero = buVector3I(0, 0, 0);

  buVector3I::buVector3I() { }

  buVector3I::buVector3I(int32 _x, int32 _y, int32 _z) : x(_x), y(_y), z(_z) { }

  buVector3I::~buVector3I() { }

  buVector3I::buVector3I(const buVector3I& _v) : x(_v.x), y(_v.y), z(_v.z) { }

  buVector3I& buVector3I::operator=(const buVector3I& _v)
  {
    x = _v.x;
    y = _v.y;
    z = _v.z;
    return *this;
  }

  void buVector3I::operator+=(const buVector3I& _v)
  {
    x += _v.x;
    y += _v.y;
    z += _v.z;
  }

  buVector3I buVector3I::operator+(const buVector3I& _v) const
  {
    return buVector3I(x + _v.x, y + _v.y, z + _v.z);
  }

  void buVector3I::operator-=(const buVector3I& _v)
  {
    x -= _v.x;
    y -= _v.y;
    z -= _v.z;
  }

  buVector3I buVector3I::operator-=(const buVector3I& _v) const
  {
    return buVector3I(x - _v.x, y - _v.y, z - _v.z);
  }

  void buVector3I::operator*=(const int32 _a)
  {
    x *= _a;
    y *= _a;
    z *= _a;
  }

  buVector3I buVector3I::operator*=(const int32 _a) const
  {
    return buVector3I(_a * x, _a * y, _a * z);
  }

  void buVector3I::operator/=(const int32 _a)
  {
    x = x / _a;
    y = y / _a;
    z = z / _a;
  }

  buVector3I buVector3I::operator/=(const int32 _a) const
  {
    return buVector3I(x / _a, y / _a, z / _a);
  }

  int32 buVector3I::dot(const buVector3I& _v) const
  {
    return x * _v.x + y * _v.y + z * _v.z;
  }

  int32 buVector3I::operator*(const buVector3I& _v) const
  {
    return x * _v.x + y * _v.y + z * _v.z;
  }

  buVector3I buVector3I::cross(const buVector3I& _v) const
  {
    return buVector3I(y * _v.z - z * _v.y,
                      z * _v.x - x * _v.z,
                      x * _v.y - y * _v.x);
  }

  void buVector3I::operator%=(const buVector3I _v)
  {
    *this = cross(_v);
  }

  buVector3I buVector3I::operator%(const buVector3I& _v) const
  {
    return buVector3I(y * _v.z - z * _v.y,
                      z * _v.x - x * _v.z,
                      x * _v.y - y * _v.x);
  }

  int32 buVector3I::mag()
  {
    int32 magnitude = std::sqrt(x * x + y * y + z * z);
    return magnitude;
  }

  void buVector3I::normalize()
  {
    int32 magnitude = std::sqrt(x * x + y * y + z * z);
    if (magnitude > 0.0f) {
      int32 oneOverMag = 1.0f / magnitude;
      x = x * oneOverMag;
      y = y * oneOverMag;
      z = z * oneOverMag;
    }
  }



}