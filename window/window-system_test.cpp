#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "window-system.h"
#include <entt/entt.hpp>
#include "../component/window.h"
#include "../component/render-viewport.h"

namespace w = soup::window;
namespace c = soup::component;

class MockWindowUtility : public w::WindowUtility {
 public:
  MOCK_METHOD(void, Init, (int * argcp,
                           char **argv,
                           const c::RenderViewport& viewport,
                           const c::Window& window), (const));
};

namespace {

TEST(WindowSystem, Init) {
  auto window_utility = MockWindowUtility{};
  auto window_system = w::WindowSystem(window_utility);

  entt::registry registry;
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

}  // namespace
