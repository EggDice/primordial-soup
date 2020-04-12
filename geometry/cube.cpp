#include "cube.h"

#include <algorithm>
#include <cstdlib>

#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/geometric.hpp>

namespace soup {
namespace geometry {

Cube::Cube(glm::vec3 position, float radius, glm::vec3 color) :
  position_(position), scale_(radius), color_(color) {}

CubeFaces Cube::GetFaces() const {
  CubeFaces faces{};
  transform(face_normals.begin(),
            face_normals.end(),
            faces.faces,
            [&] (auto& normal) {
              return GetQuad(normal);
            });
  return faces;
}

CubeEdges Cube::GetEdges() const {
  uint8_t edges_on_face = 4;
  uint8_t edges_per_direction = 3;
  CubeEdges edges{};
  auto top = GetFaceMatrix(glm::vec3(1.0f, 0.0f, 0.0f));
  auto bottom = GetFaceMatrix(glm::vec3(-1.0f, 0.0f, 0.0f));
  for (int8_t i = 0; i < edges_on_face; ++i) {
    auto edges_for_direction = GetEdgesForDirection(i, top, bottom).edges;
    std::copy(edges_for_direction,
              edges_for_direction + edges_per_direction,
              edges.edges + i * edges_per_direction);
  }
  return edges;
}

glm::vec3 Cube::GetEdgeNormal(glm::mat2x3 edge) const {
  return glm::normalize(edge[0] + edge[1] - 2.0f * position_);
}

glm::mat2x3 Cube::GetTopOrBottomFaceVertices(glm::mat4x3 face_matrix,
                                             uint8_t index) const {
  return glm::mat2x3(
    face_matrix[index],
    face_matrix[(index + 1) % edges_on_face]);
}

glm::mat2x3 Cube::GetSideFaceVertices(glm::mat4x3 top_matrix,
                                      glm::mat4x3 bottom_matrix,
                                      uint8_t index) const {
  return glm::mat2x3(
    top_matrix[index],
    bottom_matrix[(index + 2) % edges_on_face]);
}

Quad Cube::GetQuad(glm::vec3 normal) const {
  auto vertices = GetFaceMatrix(normal);
  return {color_, normal, vertices};
}

glm::mat4x3 Cube::GetFaceMatrix(glm::vec3 normal) const {
  uint8_t dimension_index = abs(glm::dot(normal, glm::vec3(0, 1, 2)));
  float direction = normal[dimension_index];
  auto face_specific_matrix = glm::transpose(glm::mat3x4(
    glm::row(face_base_matrix, (dimension_index + 2) % dimensions),
    glm::row(face_base_matrix, (dimension_index + 1) % dimensions),
    glm::row(face_base_matrix, (dimension_index) % dimensions)));
  auto position_matrix = glm::outerProduct(position_, glm::vec4(1, 1, 1, 1));
  return position_matrix + scale_ * face_specific_matrix * direction;
}

EdgesForDirection Cube::GetEdgesForDirection(uint8_t index,
                                             glm::mat4x3 top,
                                             glm::mat4x3 bottom) const {
  auto top_vertices = GetTopOrBottomFaceVertices(top, index);
  auto top_normal = GetEdgeNormal(top_vertices);
  auto bottom_vertices = GetTopOrBottomFaceVertices(bottom, index);
  auto bottom_normal = GetEdgeNormal(bottom_vertices);
  auto side_vertices = GetSideFaceVertices(top, bottom, index);
  auto side_normal = GetEdgeNormal(side_vertices);
  return  EdgesForDirection{{
    {color_, top_normal, top_vertices},
    {color_, bottom_normal, bottom_vertices},
    {color_, side_normal, side_vertices}
  }};
}

const glm::mat4x3 Cube::face_base_matrix = glm::mat4x3(
  glm::vec3(1.0f, 1.0f, 1.0f),
  glm::vec3(-1.0f, 1.0f, 1.0f),
  glm::vec3(-1.0f, -1.0f, 1.0f),
  glm::vec3(1.0f, -1.0f, 1.0f));

const uint8_t Cube::dimensions = 3;

const uint8_t Cube::edges_on_face = 4;

const std::vector<glm::vec3> Cube::face_normals = {
  glm::vec3(1.0f, 0.0f, 0.0f),
  glm::vec3(-1.0f, 0.0f, 0.0f),
  glm::vec3(0.0f, 1.0f, 0.0f),
  glm::vec3(0.0f, -1.0f, 0.0f),
  glm::vec3(0.0f, 0.0f, 1.0f),
  glm::vec3(0.0f, 0.0f, -1.0f)
};

}  // namespace geometry
}  // namespace soup
