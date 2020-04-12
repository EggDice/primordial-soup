#ifndef GEOMETRY_QUAD_H_
#define GEOMETRY_QUAD_H_

#include <glm/glm.hpp>

namespace soup {
namespace geometry {

struct Quad {
  glm::vec3 color;
  glm::vec3 normal;
  glm::mat4x3 vertices;
};

}  // namespace geometry
}  // namespace soup

#endif  // GEOMETRY_QUAD_H_
