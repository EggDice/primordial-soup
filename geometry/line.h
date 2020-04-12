#ifndef GEOMETRY_LINE_H_
#define GEOMETRY_LINE_H_

#include <glm/glm.hpp>

namespace soup {
namespace geometry {

struct Line {
  glm::vec3 color;
  glm::vec3 normal;
  glm::mat2x3 vertices;
};

}  // namespace geometry
}  // namespace soup

#endif  // GEOMETRY_LINE_H_
