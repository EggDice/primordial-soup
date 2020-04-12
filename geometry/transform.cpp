#include "transform.h"

namespace soup {
namespace geometry {

Transform::Transform() :
  Transform(glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f)
  {}

Transform::Transform(glm::vec3 position, float angle_x, float angle_y) :
  translate(position * -1.0f),
  rotate_x(glm::vec4(angle_x, 1.0f, 0.0f, 0.0f)),
  rotate_y(glm::vec4(angle_y, 0.0f, 1.0f, 0.0f))
  {}

bool Transform::operator==(const Transform& other) const {
  return glm::all(glm::equal(translate, other.translate)) &&
    glm::all(glm::equal(rotate_x, other.rotate_x)) &&
    glm::all(glm::equal(rotate_y, other.rotate_y));
}

}  // namespace geometry
}  // namespace soup
