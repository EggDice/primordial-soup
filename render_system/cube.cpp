#include "cube.h"

#include <algorithm>

#include <glm/gtc/matrix_access.hpp>

namespace soup {
namespace render_system {

Cube::Cube(glm::vec3 position, float size, glm::vec3 color) :
  position_(position), size_(size), color_(color) {}

std::vector<Quad> Cube::GetQuads() {
  const int dimensions = 3;
  std::vector<Quad> quads;
  for (int i = 0; i < dimensions; ++i) {
    quads.push_back(GetQuad(i, 1.0f));
    quads.push_back(GetQuad(i, -1.0f));
  }
  return quads;
}

Quad Cube::GetQuad(uint8_t dimensionIndex, float direction) {
  const int dimensions = 3;
  glm::vec4 rows[dimensions] = {
    glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f),
    glm::vec4(-1.0f, 1.0f, 1.0f, -1.0f),
    glm::vec4(1.0f, 1.0f, 1.0f, 1.0f) * direction
  };

  auto sideSpecificMatrix = glm::transpose(glm::mat3x4(
    rows[(dimensionIndex + 2) % 3],
    rows[(dimensionIndex + 1) % 3],
    rows[(dimensionIndex) % 3]));


  auto postitionMatrix = glm::mat4x3(
    position_,
    position_,
    position_,
    position_);


  auto scale = glm::mat3(size_ / 2);
  auto vertices = postitionMatrix + scale * sideSpecificMatrix;
  auto normal = glm::mat3(direction)[dimensionIndex];

  return {color_, normal, vertices};
}

}  // namespace render_system
}  // namespace soup
