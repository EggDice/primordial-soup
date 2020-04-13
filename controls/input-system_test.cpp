#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "input-system.h"
#include <entt/entt.hpp>

#include "../event/keyboard-event.h"

namespace cont = soup::controls;
namespace comp = soup::component;
namespace e = soup::event;


namespace {

using ::testing::_;
using ::testing::SizeIs;

TEST(InputSystem, AddKeyboardEvent) {
  cont::InputSystem input_system;

  entt::registry registry;
  auto entity = registry.create();
  registry.assign<comp::InputEvents>(entity, comp::InputEvents{});
  e::KeyboardEvent event{{e::Timer::Now()}, {e::ESC_KEY}};

  input_system.Update<e::KeyboardEvent>(registry, event);

  auto input_events = registry.get<comp::InputEvents>(entity);
  EXPECT_EQ(input_events.keyboard_events[0].time, event.time);
  EXPECT_EQ(input_events.keyboard_events[0].key_code, event.key_code);
}

}  // namespace
