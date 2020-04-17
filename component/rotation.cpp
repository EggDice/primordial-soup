#include "rotation.h"

#include <cmath>

namespace soup {
namespace component {

Rotation& Rotation::operator+=(const Rotation& other) {
  angle_x = fmod(other.angle_x + angle_x + 360, 360);
  angle_y = fmod(other.angle_y + angle_y + 360, 360);
  return *this;
}

}  // namespace component
}  // namespace soup

