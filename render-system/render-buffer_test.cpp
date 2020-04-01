#include "render-buffer.h"

#include <gtest/gtest.h>

namespace {
TEST(RenderBuffer, AllocateEmptyBuffer) {
  RenderBuffer rb(0);
  EXPECT_EQ(rb.GetQuadBuffer().size(), 0);
}
}

