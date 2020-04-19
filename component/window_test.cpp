#include "window.h"

#include <gtest/gtest.h>

namespace c = soup::component;

namespace {
TEST(Window, Equals) {
  c::Window w{"test", false};
  c::Window w2{"test", false};
  c::Window w3{"test", true};
  c::Window w4{"other", false};

  EXPECT_TRUE(w == w2);
  EXPECT_FALSE(w == w3);
  EXPECT_FALSE(w == w4);
}
}  // namespace
