#include "cube.h"

#include <gtest/gtest.h>

namespace rs = soup::render_system;

namespace {
TEST(Cube, GetQuads) {
  glm::vec3 position = {1.0f, 0.0f, 0.0f};
  glm::vec3 color = {1.0f, 1.0f, 1.0f};
  rs::Cube cube(position, 2.0f, color);
  std::vector<rs::Quad> quads = cube.GetQuads();
  EXPECT_EQ(quads[0].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(quads[0].normal, glm::vec3(1.0f, 0.0f, 0.0f));
  EXPECT_EQ(quads[0].vertices[0], glm::vec3(2.0f, -1.0f, -1.0f));
  EXPECT_EQ(quads[0].vertices[1], glm::vec3(2.0f, 1.0f, -1.0f));
  EXPECT_EQ(quads[0].vertices[2], glm::vec3(2.0f, 1.0f, 1.0f));
  EXPECT_EQ(quads[0].vertices[3], glm::vec3(2.0f, -1.0f, 1.0f));

  EXPECT_EQ(quads[1].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(quads[1].normal, glm::vec3(-1.0f, 0.0f, 0.0f));
  EXPECT_EQ(quads[1].vertices[0], glm::vec3(0.0f, -1.0f, -1.0f));
  EXPECT_EQ(quads[1].vertices[1], glm::vec3(0.0f, 1.0f, -1.0f));
  EXPECT_EQ(quads[1].vertices[2], glm::vec3(0.0f, 1.0f, 1.0f));
  EXPECT_EQ(quads[1].vertices[3], glm::vec3(0.0f, -1.0f, 1.0f));

  EXPECT_EQ(quads[2].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(quads[2].normal, glm::vec3(0.0f, 1.0f, 0.0f));
  EXPECT_EQ(quads[2].vertices[0], glm::vec3(0.0f, 1.0f, -1.0f));
  EXPECT_EQ(quads[2].vertices[1], glm::vec3(0.0f, 1.0f, 1.0f));
  EXPECT_EQ(quads[2].vertices[2], glm::vec3(2.0f, 1.0f, 1.0f));
  EXPECT_EQ(quads[2].vertices[3], glm::vec3(2.0f, 1.0f, -1.0f));

  EXPECT_EQ(quads[3].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(quads[3].normal, glm::vec3(0.0f, -1.0f, 0.0f));
  EXPECT_EQ(quads[3].vertices[0], glm::vec3(0.0f, -1.0f, -1.0f));
  EXPECT_EQ(quads[3].vertices[1], glm::vec3(0.0f, -1.0f, 1.0f));
  EXPECT_EQ(quads[3].vertices[2], glm::vec3(2.0f, -1.0f, 1.0f));
  EXPECT_EQ(quads[3].vertices[3], glm::vec3(2.0f, -1.0f, -1.0f));

  EXPECT_EQ(quads[4].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(quads[4].normal, glm::vec3(0.0f, 0.0f, 1.0f));
  EXPECT_EQ(quads[4].vertices[0], glm::vec3(0.0f, -1.0f, 1.0f));
  EXPECT_EQ(quads[4].vertices[1], glm::vec3(2.0f, -1.0f, 1.0f));
  EXPECT_EQ(quads[4].vertices[2], glm::vec3(2.0f, 1.0f, 1.0f));
  EXPECT_EQ(quads[4].vertices[3], glm::vec3(0.0f, 1.0f, 1.0f));

  EXPECT_EQ(quads[5].color, glm::vec3(1.0f, 1.0f, 1.0f));
  EXPECT_EQ(quads[5].normal, glm::vec3(0.0f, 0.0f, -1.0f));
  EXPECT_EQ(quads[5].vertices[0], glm::vec3(0.0f, -1.0f, -1.0f));
  EXPECT_EQ(quads[5].vertices[1], glm::vec3(2.0f, -1.0f, -1.0f));
  EXPECT_EQ(quads[5].vertices[2], glm::vec3(2.0f, 1.0f, -1.0f));
  EXPECT_EQ(quads[5].vertices[3], glm::vec3(0.0f, 1.0f, -1.0f));
}
}  // namespace
