#ifndef GEOMETRY_TRANSFORM_H_
#define GEOMETRY_TRANSFORM_H_

#include <glm/glm.hpp>

namespace soup {
namespace geometry {

struct Transform {
  glm::vec3 translate;
  glm::vec4 rotate_x;
  glm::vec4 rotate_y;
  Transform();
  Transform(glm::vec3 position, float angle_x, float angle_y);
  bool operator==(const Transform& other) const;
};

}  // namespace geometry
}  // namespace soup

#endif  // GEOMETRY_TRANSFORM_H_
