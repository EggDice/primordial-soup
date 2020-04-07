#include "render-buffer.h"

#include <gtest/gtest.h>

namespace rs = soup::render_system;

namespace {
TEST(RenderBuffer, AllocateEmptyBuffers) {
  rs::RenderBuffer<rs::Quad> rb(0);
  EXPECT_EQ(rb.GetBuffer().size(), 0);
  EXPECT_EQ(rb.GetBuffer().capacity(), 0);
}

TEST(RenderBuffer, AllocateValidSizeForBuffers) {
  rs::RenderBuffer<rs::Quad> rbq(1);
  EXPECT_EQ(rbq.GetBuffer().capacity(), 6);
  rs::RenderBuffer<rs::Line> rbl(1);
  EXPECT_EQ(rbl.GetBuffer().capacity(), 12);
}

TEST(RenderBuffer, RenderSingleCubeQuads) {
  rs::RenderBuffer<rs::Quad> rb(1);
  rs::Cube c{glm::vec3(0.0f, 0.0f, 0.0f), 1.0f, glm::vec3(1.0f, 1.0f, 1.0f)};
  rb.AddCube(c);
  rb.Render();
  EXPECT_EQ(rb.GetBuffer().size(), 6);
}

TEST(RenderBuffer, RenderSingleCubeLines) {
  rs::RenderBuffer<rs::Line> rb(1);
  rs::Cube c{glm::vec3(0.0f, 0.0f, 0.0f), 1.0f, glm::vec3(1.0f, 1.0f, 1.0f)};
  rb.AddCube(c);
  rb.Render();
  EXPECT_EQ(rb.GetBuffer().size(), 12);
}

TEST(RenderBuffer, ClearBuffer) {
  rs::RenderBuffer<rs::Quad> rb(1);
  rs::Cube c{glm::vec3(0.0f, 0.0f, 0.0f), 1.0f, glm::vec3(1.0f, 1.0f, 1.0f)};
  rb.AddCube(c);
  rb.Render();
  rb.Clear();
  EXPECT_EQ(rb.GetBuffer().size(), 0);
  EXPECT_EQ(rb.GetBuffer().capacity(), 6);
}

TEST(RenderBuffer, ClearCubes) {
  rs::RenderBuffer<rs::Quad> rb(1);
  rs::Cube c{glm::vec3(0.0f, 0.0f, 0.0f), 1.0f, glm::vec3(1.0f, 1.0f, 1.0f)};
  rb.AddCube(c);
  rb.Render();
  rb.Clear();
  rb.AddCube(c);
  rb.Render();
  EXPECT_EQ(rb.GetBuffer().size(), 6);
}

TEST(RenderBuffer, RenderMultiple) {
  rs::RenderBuffer<rs::Quad> rb(1);
  rs::Cube c{glm::vec3(0.0f, 0.0f, 0.0f), 1.0f, glm::vec3(1.0f, 1.0f, 1.0f)};
  rb.AddCube(c);
  rb.AddCube(c);
  rb.Render();
  EXPECT_EQ(rb.GetBuffer().size(), 12);
}
}  // namespace

