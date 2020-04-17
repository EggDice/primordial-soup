#include "rotation.h"

#include <gtest/gtest.h>

namespace c = soup::component;

namespace {
TEST(Rotation, PlusEquals) {
  auto r = c::Rotation{2.0f, 2.0f};
  auto r2 = c::Rotation{5.0f, 5.0f};
  r += r2;
  EXPECT_EQ(r.angle_x, 7.0f);
  EXPECT_EQ(r.angle_y, 7.0f);
}

TEST(Rotation, BoundUnder360) {
  auto r = c::Rotation{358.0f, 358.0f};
  auto r2 = c::Rotation{5.0f, 5.0f};
  r += r2;
  EXPECT_EQ(r.angle_x, 3.0f);
  EXPECT_EQ(r.angle_y, 3.0f);
}

TEST(Rotation, BoundOver0) {
  auto r = c::Rotation{0.0f, 0.0f};
  auto r2 = c::Rotation{-5.0f, -5.0f};
  r += r2;
  EXPECT_EQ(r.angle_x, 355.0f);
  EXPECT_EQ(r.angle_y, 355.0f);
}
}  // namespace
