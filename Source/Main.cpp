#include <iostream>

#include "Vector3D.h"

int main(int argc, char *argv[]) {
  Len::Vector3D v(1.f, 2.f, 3.f);
  std::cout << "Vector magnitude: " << Len::Magnitude(v) << std::endl;
  return 0;
}
