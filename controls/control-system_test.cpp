
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>

#include "control-system.h"
#include <entt/entt.hpp>
#include "../component/input-events.h"
#include "../component/rotation.h"
#include "../component/control-keyboard-rotate.h"
#include "../component/render-viewport.h"
#include "../component/control-resize.h"
#include "../component/window.h"
#include "../component/control-exit.h"
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
  }, {
    e::ResizeEvent{e::Timer::Now(), 600, 400}
  }});

  control_system.Update(registry, e::TickEvent{e::Timer::Now()});

  auto inputs = registry.get<comp::InputEvents>(input_entity);

  EXPECT_EQ(inputs.keyboard_events.size(), 0);
  EXPECT_EQ(inputs.resize_events.size(), 0);
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

TEST(ControlSystem, ResizeEvent) {
  cont::ControlSystem control_system{};
  entt::registry registry;
  auto input_entity = registry.create();
  registry.assign<comp::InputEvents>(input_entity, comp::InputEvents{{}, {
    e::ResizeEvent{e::ResizeEvent{e::Timer::Now(), 600, 400}}
  }});

  auto entity = registry.create();
  registry.assign<comp::RenderViewport>(entity,
                                        comp::RenderViewport{100, 100});
  registry.assign<comp::ControlResize>(entity, comp::ControlResize{});

  control_system.Update(registry, e::TickEvent{e::Timer::Now()});

  auto viewport = registry.get<comp::RenderViewport>(entity);

  EXPECT_EQ(viewport.width, 600);
  EXPECT_EQ(viewport.height, 400);
}

TEST(ControlSystem, Exit) {
  cont::ControlSystem control_system{};
  entt::registry registry;
  auto input_entity = registry.create();
  registry.assign<comp::InputEvents>(input_entity, comp::InputEvents{{
    e::KeyboardEvent{e::Timer::Now(), e::ESC_KEY},
  }});

  auto entity = registry.create();
  registry.assign<comp::Window>(entity,
                                comp::Window{"window", false});
  registry.assign<comp::ControlExit>(entity, comp::ControlExit{e::ESC_KEY});

  control_system.Update(registry, e::TickEvent{e::Timer::Now()});

  auto window = registry.get<comp::Window>(entity);

  EXPECT_EQ(window.is_exit, true);
}
}  // namespace
