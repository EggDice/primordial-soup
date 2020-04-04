#ifndef RENDER_SYSTEM_LINE_H_
#define RENDER_SYSTEM_LINE_H_

#include <glm/glm.hpp>

namespace soup {
namespace render_system {

struct Line {
  glm::vec3 color;
  glm::mat2x3 vertices;
};

}  // namespace render_system
}  // namespace soup

#endif  // RENDER_SYSTEM_LINE_H_
