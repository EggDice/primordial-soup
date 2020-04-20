#include <gtest/gtest.h>

#include "window-system.h"
#include "mock-window-utility.h"
#include <entt/entt.hpp>
#include "../component/window.h"
#include "../component/render-viewport.h"

namespace {
namespace w = soup::window;
namespace c = soup::component;
namespace e = soup::event;

using ::testing::NiceMock;

TEST(WindowSystem, Init) {
  auto window_utility = NiceMock<w::MockWindowUtility>{};
  auto window_system = w::WindowSystem(window_utility);
  auto registry = entt::registry{};
  auto entity = registry.create();
  auto window = c::Window{"Window", false};
  auto viewport = c::RenderViewport{500, 500};
  registry.assign<c::Window>(entity, window);
  registry.assign<c::RenderViewport>(entity, viewport);

  int argc = 0;
  char ** argv = nullptr;

  EXPECT_CALL(window_utility, Init(&argc, argv, viewport, window))
    .Times(1);

  window_system.Init(registry, &argc, argv);
}

TEST(WindowSystem, Exit) {
  auto window_utility = NiceMock<w::MockWindowUtility>{};
  auto window_system = w::WindowSystem(window_utility);
  auto registry = entt::registry{};
  auto entity = registry.create();
  auto window = c::Window{"Window", true};
  registry.assign<c::Window>(entity, window);

  EXPECT_CALL(window_utility, Exit())
    .Times(1);

  window_system.Update(registry, e::TickEvent{e::Timer::Now()});
}

}  // namespace
