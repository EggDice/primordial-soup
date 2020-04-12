#include "transform.h"

#include <math.h>
#include <gtest/gtest.h>

namespace g = soup::geometry;

namespace {
TEST(Transform, DefaultConstructor) {
  g::Transform t = g::Transform();

  EXPECT_EQ(t.translate, glm::vec3(0.0f, 0.0f, 0.0f));
  EXPECT_EQ(t.rotate_x, glm::vec4(0.0f, 1.0f, 0.0f, 0.0f));
  EXPECT_EQ(t.rotate_y, glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
}

TEST(Transform, Constructor) {
  glm::vec3 position = {1.0f, 1.0f, 1.0f};
  g::Transform t(position, 45.0f, 45.0f);

  EXPECT_EQ(t.translate, glm::vec3(-1.0f, -1.0f, -1.0f));
  EXPECT_EQ(t.rotate_x, glm::vec4(45.0f, 1.0f, 0.0f, 0.0f));
  EXPECT_EQ(t.rotate_y, glm::vec4(45.0f, 0.0f, 1.0f, 0.0f));
}

TEST(Transform, Equals) {
  glm::vec3 position = {1.0f, 1.0f, 1.0f};
  g::Transform t(position, 45.0f, 45.0f);
  g::Transform t2(position, 45.0f, 45.0f);
  g::Transform t3(position, 0.0f, 45.0f);

  EXPECT_TRUE(t == t2);
  EXPECT_FALSE(t == t3);
}
}  // namespace
