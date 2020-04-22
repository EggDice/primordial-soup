#include "window-system.h"


#include "../component/render-viewport.h"
#include "../component/window.h"

namespace soup {
namespace window {

WindowSystem::WindowSystem(const WindowUtility& window_utility) :
  window_utility_(window_utility) {}

void WindowSystem::Init(entt::registry& registry,
                          int* argcp,
                          char ** argv) {
  registry.view<
    component::Window,
    component::RenderViewport
  >().each([&argcp, &argv, this] (auto& window, auto& viewport) {
    window_utility_.Init(argcp, argv, viewport, window);
  });
}

void WindowSystem::Update(entt::registry& registry,
                          const event::TickEvent& event) {
  registry.view<
    component::Window
  >().each([this] (auto& window) {
    if (window.is_exit) {
      window_utility_.Exit();
    }
  });
}

}  // namespace window
}  // namespace soup

