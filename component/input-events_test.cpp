#include <gtest/gtest.h>

#include "input-events.h"
#include "../event/keyboard-event.h"
#include "../event/resize-event.h"

namespace c = soup::component;
namespace e = soup::event;

namespace {
TEST(InputEvents, Add) {
  auto input_events = c::InputEvents{};
  auto keyboard_event = e::KeyboardEvent{};
  input_events.Add(keyboard_event);
  EXPECT_EQ(input_events.keyboard_events.size(), 1);
  auto resize_event = e::ResizeEvent{};
  input_events.Add(resize_event);
  EXPECT_EQ(input_events.resize_events.size(), 1);
}
}  // namespace
