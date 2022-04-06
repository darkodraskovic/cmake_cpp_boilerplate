#include "Vector3D.h"

namespace Len {

Vector3D::Vector3D(float x, float y, float z) : x_(x), y_(y), z_(z){};
float& Vector3D::operator[](int i) { return (&x_)[i]; };
const float& Vector3D::operator[](int i) const { return (&x_)[i]; };

}  // namespace Len
