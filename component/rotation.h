#ifndef COMPONENT_ROTATION_H_
#define COMPONENT_ROTATION_H_

namespace soup {
namespace component {

struct Rotation {
  float angle_x;
  float angle_y;
  Rotation& operator+=(const Rotation& other);
};

}  // namespace component
}  // namespace soup

#endif  // COMPONENT_ROTATION_H_
