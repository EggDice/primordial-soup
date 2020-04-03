#ifndef RENDER_SYSTEM_CUBE_H_
#define RENDER_SYSTEM_CUBE_H_

#include <vector>

#include <glm/glm.hpp>

#include "quad.h"

namespace soup {
namespace render_system {

struct Cube {
 public:
  Cube(glm::vec3 position, float size, glm::vec3 color);
  std::vector<Quad> GetQuads();
 private:
  glm::vec3 position_;
  float size_;
  glm::vec3 color_;
  Quad GetQuad(uint8_t dimensionIndex, float direction);
};

}  // namespace render_system
}  // namespace soup

#endif  // RENDER_SYSTEM_CUBE_H_
