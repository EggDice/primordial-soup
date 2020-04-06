#ifndef RENDER_SYSTEM_CUBE_H_
#define RENDER_SYSTEM_CUBE_H_

#include <vector>

#include <glm/glm.hpp>

#include "quad.h"
#include "line.h"

namespace soup {
namespace render_system {

struct Cube {
 public:
  Cube(glm::vec3 position, float radius, glm::vec3 color);
  std::vector<Quad> GetQuads() const;
  std::vector<Line> GetLines() const;
 private:
  glm::vec3 position_;
  glm::mat3 scale_;
  glm::vec3 color_;
  Quad GetQuad(uint8_t dimension_index, float direction) const;
  glm::mat4x3 GetSideMatrix(uint8_t dimension_index, float direction) const;
  glm::mat2x3 GetTopBottomSideVertices(glm::mat4x3 side_matrix,
                                       uint8_t index) const;
  static const glm::mat4x3 side_base_matrix;
  static const uint8_t dimensions;
  static const uint8_t edges_on_side;
};

}  // namespace render_system
}  // namespace soup

#endif  // RENDER_SYSTEM_CUBE_H_
