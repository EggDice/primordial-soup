#ifndef RENDER_SYSTEM_QUAD_H_
#define RENDER_SYSTEM_QUAD_H_

#include <glm/glm.hpp>

namespace soup {
namespace render_system {

struct Quad {
  glm::vec3 color;
  glm::vec3 normal;
  glm::mat4x3 vertices;
};

}  // namespace render_system
}  // namespace soup

#endif  // RENDER_SYSTEM_QUAD_H_
