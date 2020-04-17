#include "window.h"

#include <math.h>
#include <gtest/gtest.h>

namespace c = soup::component;

namespace {
TEST(Window, Equals) {
  c::Window w{50, 50, "test"};
  c::Window w2{50, 50, "test"};
  c::Window w3{100, 50, "test"};
  c::Window w4{50, 100, "test"};
  c::Window w5{50, 50, "other"};

  EXPECT_TRUE(w == w2);
  EXPECT_FALSE(w == w3);
  EXPECT_FALSE(w == w4);
  EXPECT_FALSE(w == w5);
}
}  // namespace
