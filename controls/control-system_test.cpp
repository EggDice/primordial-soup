
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>

#include "control-system.h"
#include <entt/entt.hpp>
#include "../component/input-events.h"
#include "../component/rotation.h"
#include "../component/control-keyboard-rotate.h"
#include "../event/timer.h"

namespace cont = soup::controls;
namespace comp = soup::component;
namespace e = soup::event;

namespace {
TEST(ControlSystem, EmptyInputs) {
  cont::ControlSystem control_system{};
  entt::registry registry;
  auto input_entity = registry.create();
  registry.assign<comp::InputEvents>(input_entity, comp::InputEvents{{
    e::KeyboardEvent{e::Timer::Now(), e::ARROW_UP_KEY}
  }});

  control_system.Update(registry, e::TickEvent{e::Timer::Now()});

  auto inputs = registry.get<comp::InputEvents>(input_entity);

  EXPECT_EQ(inputs.keyboard_events.size(), 0);
}

TEST(ControlSystem, Rotate) {
  cont::ControlSystem control_system{};
  entt::registry registry;
  auto input_entity = registry.create();
  registry.assign<comp::InputEvents>(input_entity, comp::InputEvents{{
    e::KeyboardEvent{e::Timer::Now(), e::ARROW_UP_KEY}
  }});

  auto entity = registry.create();
  registry.assign<comp::Rotation>(entity, comp::Rotation{5.0f, 5.0f});
  auto keyboard_rotate = comp::ControlKeyBoardRotate{{
    {e::ARROW_UP_KEY, {5.0f, 5.0f}}
  }};
  registry.assign<comp::ControlKeyBoardRotate>(entity, keyboard_rotate);


  control_system.Update(registry, e::TickEvent{e::Timer::Now()});

  auto rotate = registry.get<comp::Rotation>(entity);

  EXPECT_EQ(rotate.angle_x, 10.0f);
  EXPECT_EQ(rotate.angle_y, 10.0f);
}
TEST(ControlSystem, IgnoreKeys) {
  cont::ControlSystem control_system{};
  entt::registry registry;
  auto input_entity = registry.create();
  registry.assign<comp::InputEvents>(input_entity, comp::InputEvents{{
    e::KeyboardEvent{e::Timer::Now(), e::ARROW_UP_KEY},
    e::KeyboardEvent{e::Timer::Now(), e::ARROW_DOWN_KEY},
    e::KeyboardEvent{e::Timer::Now(), e::ARROW_LEFT_KEY},
    e::KeyboardEvent{e::Timer::Now(), e::ARROW_RIGHT_KEY},
  }});

  auto entity = registry.create();
  registry.assign<comp::Rotation>(entity, comp::Rotation{5.0f, 5.0f});
  auto keyboard_rotate = comp::ControlKeyBoardRotate{{
    {e::ARROW_DOWN_KEY, {5.0f, 5.0f}},
    {e::ARROW_UP_KEY, {2.0f, 2.0f}},
  }};
  registry.assign<comp::ControlKeyBoardRotate>(entity, keyboard_rotate);


  control_system.Update(registry, e::TickEvent{e::Timer::Now()});

  auto rotate = registry.get<comp::Rotation>(entity);

  EXPECT_EQ(rotate.angle_x, 12.0f);
  EXPECT_EQ(rotate.angle_y, 12.0f);
}
}  // namespace
