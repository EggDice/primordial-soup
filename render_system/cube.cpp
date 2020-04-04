#include "cube.h"

#include <iostream>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include <glm/gtc/matrix_access.hpp>

namespace soup {
namespace render_system {

Cube::Cube(glm::vec3 position, float radius, glm::vec3 color) :
  position_(position), scale_(radius), color_(color) {}

std::vector<Quad> Cube::GetQuads() {
  std::vector<Quad> quads;
  quads.reserve(6);
  for (int8_t i = 0; i < dimensions; ++i) {
    quads.push_back(GetQuad(i, 1.0f));
    quads.push_back(GetQuad(i, -1.0f));
  }
  return quads;
}

std::vector<Line> Cube::GetLines() {
  uint8_t edges_on_side = 4;
  std::vector<Line> lines;
  lines.reserve(12);

  auto top_base_matrix = GetSideMatrix(0, 1.0f);
  auto bottom_base_matrix = GetSideMatrix(0, -1.0f);

  for (int8_t i = 0; i < edges_on_side; ++i) {
    auto top_vertices = GetTopBottomSideVertices(top_base_matrix, i);
    lines.push_back({color_, top_vertices});
    auto bottom_vertices = GetTopBottomSideVertices(bottom_base_matrix, i);
    lines.push_back({color_, bottom_vertices});
    auto edge_vertices = glm::mat2x3(
      top_base_matrix[i],
      bottom_base_matrix[i]);
    lines.push_back({color_, edge_vertices});
  }
  return lines;
}

glm::mat2x3 Cube::GetTopBottomSideVertices(glm::mat4x3 side_matrix,
                                           uint8_t index) {
  return glm::mat2x3(
    side_matrix[index],
    side_matrix[(index + 1) % edges_on_side]);
}

Quad Cube::GetQuad(uint8_t dimension_index, float direction) {
  auto vertices = GetSideMatrix(dimension_index, direction);
  auto normal = glm::mat3(direction)[dimension_index];
  return {color_, normal, vertices};
}

glm::mat4x3 Cube::GetSideMatrix(uint8_t dimension_index, float direction) {
  auto dimension_specific_matrix = glm::mat3x4(
    glm::row(side_base_matrix, 2),
    glm::row(side_base_matrix, 1),
    glm::row(side_base_matrix, 0) * direction);

  auto side_specific_matrix = glm::transpose(glm::mat3x4(
    dimension_specific_matrix[(dimension_index + 2) % dimensions],
    dimension_specific_matrix[(dimension_index + 1) % dimensions],
    dimension_specific_matrix[(dimension_index) % dimensions]));

  auto position_matrix = glm::mat4x3(
    position_,
    position_,
    position_,
    position_);

  return position_matrix + scale_ * side_specific_matrix;
}

const glm::mat4x3 Cube::side_base_matrix = glm::mat4x3(
  glm::vec3(1.0f, 1.0f, 1.0f),
  glm::vec3(1.0f, 1.0f, -1.0f),
  glm::vec3(1.0f, -1.0f, -1.0f),
  glm::vec3(1.0f, -1.0f, 1.0f));

const uint8_t Cube::dimensions = 3;

const uint8_t Cube::edges_on_side = 4;

}  // namespace render_system
}  // namespace soup
