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
  Quad GetQuad(glm::vec3 normal) const;
  glm::mat4x3 GetFaceMatrix(glm::vec3 normal) const;
  glm::mat2x3 GetTopOrBottomFaceVertices(glm::mat4x3 face_matrix,
                                         uint8_t index) const;
  glm::mat2x3 GetSideFaceVertices(glm::mat4x3 top_matrix,
                                  glm::mat4x3 bottom_matrix,
                                  uint8_t index) const;
  static const glm::mat4x3 face_base_matrix;
  static const uint8_t dimensions;
  static const uint8_t edges_on_face;
  static const std::vector<glm::vec3> face_normals;
};

}  // namespace render_system
}  // namespace soup

#endif  // RENDER_SYSTEM_CUBE_H_
