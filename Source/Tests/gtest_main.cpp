#include <gtest/gtest.h>

#include "Vector3D.h"

// Demonstrate some basic assertions.
TEST(MathTest, Vector3D) {
  float x = 1.f, y = 2.f, z = 3.f;
  Len::Vector3D v(x, y, z);
  EXPECT_EQ(v.x_, x);
  EXPECT_EQ(v[2], z);
  EXPECT_NE(v[1], z);

  Len::Vector3D v0 = -v;
  EXPECT_EQ(v0.x_, -x);
  EXPECT_EQ(v0.y_, -y);
  EXPECT_EQ(v0.z_, -z);

  float factor = 2.f;
  float absError = 10 - 6.f;
  v0 = v * factor;
  EXPECT_NEAR(v0.x_, x * factor, absError);
  EXPECT_NEAR(v0.y_, y * factor, absError);
  EXPECT_NEAR(v0.z_, z * factor, absError);

  v0 = v / factor;
  EXPECT_NEAR(v0.x_, x / factor, absError);
  EXPECT_NEAR(v0.y_, y / factor, absError);
  EXPECT_NEAR(v0.z_, z / factor, absError);

  float magnitude = sqrtf(v.x_ * v.x_ + v.y_ * v.y_ + v.z_ * v.z_);
  EXPECT_NEAR(Len::Magnitude(v), magnitude, absError);
  EXPECT_NEAR(Len::Magnitude(Len::Normalize(v)), 1, absError);
}
