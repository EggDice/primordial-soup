#include "cube.h"

#include <math.h>
#include <gtest/gtest.h>

namespace g = soup::geometry;

namespace {
TEST(Cube, GetFaces) {
  glm::vec3 position = {1.0f, 0.0f, 0.0f};
  glm::vec3 color = {1.0f, 1.0f, 1.0f};
  g::Cube cube(position, 1.0f, color);
  g::CubeFaces faces = cube.GetFaces();

  EXPECT_EQ(faces.faces[0].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(faces.faces[0].normal, glm::vec3(1.0f, 0.0f, 0.0f));
  EXPECT_EQ(faces.faces[0].vertices[0], glm::vec3(2.0f, 1.0f, 1.0f));
  EXPECT_EQ(faces.faces[0].vertices[1], glm::vec3(2.0f, 1.0f, -1.0f));
  EXPECT_EQ(faces.faces[0].vertices[2], glm::vec3(2.0f, -1.0f, -1.0f));
  EXPECT_EQ(faces.faces[0].vertices[3], glm::vec3(2.0f, -1.0f, 1.0f));

  EXPECT_EQ(faces.faces[1].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(faces.faces[1].normal, glm::vec3(-1.0f, 0.0f, 0.0f));
  EXPECT_EQ(faces.faces[1].vertices[0], glm::vec3(0.0f, -1.0f, -1.0f));
  EXPECT_EQ(faces.faces[1].vertices[1], glm::vec3(0.0f, -1.0f, 1.0f));
  EXPECT_EQ(faces.faces[1].vertices[2], glm::vec3(0.0f, 1.0f, 1.0f));
  EXPECT_EQ(faces.faces[1].vertices[3], glm::vec3(0.0f, 1.0f, -1.0f));

  EXPECT_EQ(faces.faces[2].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(faces.faces[2].normal, glm::vec3(0.0f, 1.0f, 0.0f));
  EXPECT_EQ(faces.faces[2].vertices[0], glm::vec3(2.0f, 1.0f, 1.0f));
  EXPECT_EQ(faces.faces[2].vertices[1], glm::vec3(0.0f, 1.0f, 1.0f));
  EXPECT_EQ(faces.faces[2].vertices[2], glm::vec3(0.0f, 1.0f, -1.0f));
  EXPECT_EQ(faces.faces[2].vertices[3], glm::vec3(2.0f, 1.0f, -1.0f));

  EXPECT_EQ(faces.faces[3].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(faces.faces[3].normal, glm::vec3(0.0f, -1.0f, 0.0f));
  EXPECT_EQ(faces.faces[3].vertices[0], glm::vec3(0.0f, -1.0f, -1.0f));
  EXPECT_EQ(faces.faces[3].vertices[1], glm::vec3(2.0f, -1.0f, -1.0f));
  EXPECT_EQ(faces.faces[3].vertices[2], glm::vec3(2.0f, -1.0f, 1.0f));
  EXPECT_EQ(faces.faces[3].vertices[3], glm::vec3(0.0f, -1.0f, 1.0f));

  EXPECT_EQ(faces.faces[4].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(faces.faces[4].normal, glm::vec3(0.0f, 0.0f, 1.0f));
  EXPECT_EQ(faces.faces[4].vertices[0], glm::vec3(2.0f, 1.0f, 1.0f));
  EXPECT_EQ(faces.faces[4].vertices[1], glm::vec3(2.0f, -1.0f, 1.0f));
  EXPECT_EQ(faces.faces[4].vertices[2], glm::vec3(0.0f, -1.0f, 1.0f));
  EXPECT_EQ(faces.faces[4].vertices[3], glm::vec3(0.0f, 1.0f, 1.0f));

  EXPECT_EQ(faces.faces[5].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(faces.faces[5].normal, glm::vec3(0.0f, 0.0f, -1.0f));
  EXPECT_EQ(faces.faces[5].vertices[0], glm::vec3(0.0f, -1.0f, -1.0f));
  EXPECT_EQ(faces.faces[5].vertices[1], glm::vec3(0.0f, 1.0f, -1.0f));
  EXPECT_EQ(faces.faces[5].vertices[2], glm::vec3(2.0f, 1.0f, -1.0f));
  EXPECT_EQ(faces.faces[5].vertices[3], glm::vec3(2.0f, -1.0f, -1.0f));
}

TEST(Cube, GetEdges) {
  float half_sqrt2 = sqrt(2) / 2.0;
  glm::vec3 position = {1.0f, 0.0f, 0.0f};
  glm::vec3 color = {1.0f, 1.0f, 1.0f};
  g::Cube cube(position, 2.0f, color);
  g::CubeEdges edges = cube.GetEdges();

  EXPECT_EQ(edges.edges[0].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(edges.edges[0].normal, glm::vec3(half_sqrt2, half_sqrt2, 0.0f));
  EXPECT_EQ(edges.edges[0].vertices[0], glm::vec3(3.0f, 2.0f, 2.0f));
  EXPECT_EQ(edges.edges[0].vertices[1], glm::vec3(3.0f, 2.0f, -2.0f));

  EXPECT_EQ(edges.edges[1].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(edges.edges[1].normal, glm::vec3(-half_sqrt2, -half_sqrt2, 0.0f));
  EXPECT_EQ(edges.edges[1].vertices[0], glm::vec3(-1.0f, -2.0f, -2.0f));
  EXPECT_EQ(edges.edges[1].vertices[1], glm::vec3(-1.0f, -2.0f, 2.0f));

  EXPECT_EQ(edges.edges[2].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(edges.edges[2].normal, glm::vec3(0.0f, half_sqrt2, half_sqrt2));
  EXPECT_EQ(edges.edges[2].vertices[0], glm::vec3(3.0f, 2.0f, 2.0f));
  EXPECT_EQ(edges.edges[2].vertices[1], glm::vec3(-1.0f, 2.0f, 2.0f));

  EXPECT_EQ(edges.edges[3].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(edges.edges[3].normal, glm::vec3(half_sqrt2, 0.0f, -half_sqrt2));
  EXPECT_EQ(edges.edges[3].vertices[0], glm::vec3(3.0f, 2.0f, -2.0f));
  EXPECT_EQ(edges.edges[3].vertices[1], glm::vec3(3.0f, -2.0f, -2.0f));

  EXPECT_EQ(edges.edges[4].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(edges.edges[4].normal, glm::vec3(-half_sqrt2, 0.0f, half_sqrt2));
  EXPECT_EQ(edges.edges[4].vertices[0], glm::vec3(-1.0f, -2.0f, 2.0f));
  EXPECT_EQ(edges.edges[4].vertices[1], glm::vec3(-1.0f, 2.0f, 2.0f));

  EXPECT_EQ(edges.edges[5].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(edges.edges[5].normal, glm::vec3(0.0f, half_sqrt2, -half_sqrt2));
  EXPECT_EQ(edges.edges[5].vertices[0], glm::vec3(3.0f, 2.0f, -2.0f));
  EXPECT_EQ(edges.edges[5].vertices[1], glm::vec3(-1.0f, 2.0f, -2.0f));

  EXPECT_EQ(edges.edges[6].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(edges.edges[6].normal, glm::vec3(half_sqrt2, -half_sqrt2, 0.0f));
  EXPECT_EQ(edges.edges[6].vertices[0], glm::vec3(3.0f, -2.0f, -2.0f));
  EXPECT_EQ(edges.edges[6].vertices[1], glm::vec3(3.0f, -2.0f, 2.0f));

  EXPECT_EQ(edges.edges[7].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(edges.edges[7].normal, glm::vec3(-half_sqrt2, half_sqrt2, 0.0f));
  EXPECT_EQ(edges.edges[7].vertices[0], glm::vec3(-1.0f, 2.0f, 2.0f));
  EXPECT_EQ(edges.edges[7].vertices[1], glm::vec3(-1.0f, 2.0f, -2.0f));

  EXPECT_EQ(edges.edges[8].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(edges.edges[8].normal, glm::vec3(0.0f, -half_sqrt2, -half_sqrt2));
  EXPECT_EQ(edges.edges[8].vertices[0], glm::vec3(3.0f, -2.0f, -2.0f));
  EXPECT_EQ(edges.edges[8].vertices[1], glm::vec3(-1.0f, -2.0f, -2.0f));

  EXPECT_EQ(edges.edges[9].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(edges.edges[9].normal, glm::vec3(half_sqrt2, 0.0f, half_sqrt2));
  EXPECT_EQ(edges.edges[9].vertices[0], glm::vec3(3.0f, -2.0f, 2.0f));
  EXPECT_EQ(edges.edges[9].vertices[1], glm::vec3(3.0f, 2.0f, 2.0f));

  EXPECT_EQ(edges.edges[10].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(edges.edges[10].normal, glm::vec3(-half_sqrt2, 0.0f, -half_sqrt2));
  EXPECT_EQ(edges.edges[10].vertices[0], glm::vec3(-1.0f, 2.0f, -2.0f));
  EXPECT_EQ(edges.edges[10].vertices[1], glm::vec3(-1.0f, -2.0f, -2.0f));

  EXPECT_EQ(edges.edges[11].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(edges.edges[11].normal, glm::vec3(0.0f, -half_sqrt2, half_sqrt2));
  EXPECT_EQ(edges.edges[11].vertices[0], glm::vec3(3.0f, -2.0f, 2.0f));
  EXPECT_EQ(edges.edges[11].vertices[1], glm::vec3(-1.0f, -2.0f, 2.0f));
}
}  // namespace
