#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "window-system.h"
#include <entt/entt.hpp>
#include "../component/window.h"
#include "../component/render-viewport.h"

namespace w = soup::window;
namespace c = soup::component;
namespace e = soup::event;

class MockWindowUtility : public w::WindowUtility {
 public:
  MOCK_METHOD(void, Init, (int * argcp,
                           char **argv,
                           const c::RenderViewport& viewport,
                           const c::Window& window), (const));
  MOCK_METHOD(void, Exit, (), (const));
  MOCK_METHOD(void, RegisterKeyboardFunction, ((void (*func)(unsigned char key,
                                             int x, int y))), (const));
  MOCK_METHOD(void, RegisterKeyboardSpecialFunction, ((void (*func)(int key,
                                                    int x, int y))), (const));
  MOCK_METHOD(void, RegisterResizeFunction, ((void (*func)(int width,
                                                           int height))),
                                            (const));
  MOCK_METHOD(void, RegisterMouseFunction, ((void (*func)(int button,
                                          int state,
                                          int x, int y))), (const));
  MOCK_METHOD(void, RegisterDisplayFunction, ((void (*func)(void))), (const));
  MOCK_METHOD(void, RegisterTickFunc, ((void (*func)(int value))), (const));
  MOCK_METHOD(void, StartMainLoop, (), (const));
  MOCK_METHOD(void, PostRedisplay, (), (const));
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

TEST(WindowSystem, Exit) {
  auto window_utility = MockWindowUtility{};
  auto window_system = w::WindowSystem(window_utility);

  entt::registry registry;
  auto entity = registry.create();
  auto window = c::Window{"Window", true};
  registry.assign<c::Window>(entity, window);

  EXPECT_CALL(window_utility, Exit())
    .Times(1);

  window_system.Update(registry, e::TickEvent{e::Timer::Now()});
}

}  // namespace
