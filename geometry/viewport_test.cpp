#include "viewport.h"

#include <gtest/gtest.h>

namespace g = soup::geometry;

namespace {
TEST(Viewport, Equals) {
  g::Viewport v{50, 50};
  g::Viewport v2{50, 50};
  g::Viewport v3{100, 50};
  g::Viewport v4{50, 100};

  EXPECT_TRUE(v == v2);
  EXPECT_FALSE(v == v3);
  EXPECT_FALSE(v == v4);
}
}  // namespace
