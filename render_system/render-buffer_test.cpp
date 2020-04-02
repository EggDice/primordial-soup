#include "render-buffer.h"

#include <gtest/gtest.h>

namespace rs = soup::render_system;

namespace {
TEST(RenderBuffer, AllocateEmptyBuffers) {
  rs::RenderBuffer rb(0);
  EXPECT_EQ(rb.GetCubeBuffer().size(), 0);
  EXPECT_EQ(rb.GetQuadBuffer().size(), 0);
}

TEST(RenderBuffer, AllocateValidSizeForBuffers) {
  rs::RenderBuffer rb(1);
  EXPECT_EQ(rb.GetCubeBuffer().size(), 0);
  EXPECT_EQ(rb.GetCubeBuffer().capacity(), 1);
  EXPECT_EQ(rb.GetQuadBuffer().size(), 0);
  EXPECT_EQ(rb.GetQuadBuffer().capacity(), 6);
}

TEST(RenderBuffer, RenderSingleCube) {
  rs::RenderBuffer rb(1);

  // EXPECT_EQ(rb.);
}
}  // namespace

