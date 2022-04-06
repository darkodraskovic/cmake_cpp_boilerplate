#include <math.h>
namespace Len {

struct Vector3D {
  float x_, y_, z_;
  Vector3D() = default;
  Vector3D(float x, float y, float z);

  float& operator[](int i);
  const float& operator[](int i) const;

  Vector3D& operator*=(float s);
  Vector3D& operator/=(float s);
};
inline Vector3D operator*(const Vector3D& v, float s) {
  return Vector3D(v.x_ * s, v.y_ * s, v.z_ * s);
};
inline Vector3D operator/(const Vector3D& v, float s) {
  s = 1.0f / s;
  return Vector3D(v.x_ * s, v.y_ * s, v.z_ * s);
};
inline Vector3D operator-(const Vector3D& v) {
  return Vector3D(-v.x_, -v.y_, -v.z_);
};

inline float Magnitude(const Vector3D& v) {
  return sqrtf(v.x_ * v.x_ + v.y_ * v.y_ + v.z_ * v.z_);
};

inline Vector3D Normalize(const Vector3D& v) { return v / Magnitude(v); };

}  // namespace Len
