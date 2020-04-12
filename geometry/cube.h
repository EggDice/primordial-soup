#ifndef GEOMETRY_CUBE_H_
#define GEOMETRY_CUBE_H_

#include <vector>

#include <glm/glm.hpp>

#include "cube-edges.h"
#include "cube-faces.h"

namespace soup {
namespace geometry {

struct EdgesForDirection {
  Line edges[3];
};

struct Cube {
 public:
  Cube(glm::vec3 position, float radius, glm::vec3 color);
  CubeEdges GetEdges() const;
  CubeFaces GetFaces() const;
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
  glm::vec3 GetEdgeNormal(glm::mat2x3 edge) const;
  EdgesForDirection GetEdgesForDirection(uint8_t index,
                                         glm::mat4x3 top,
                                         glm::mat4x3 bottom) const;
  static const glm::mat4x3 face_base_matrix;
  static const uint8_t dimensions;
  static const uint8_t edges_on_face;
  static const std::vector<glm::vec3> face_normals;
};

}  // namespace geometry
}  // namespace soup

#endif  // GEOMETRY_CUBE_H_
