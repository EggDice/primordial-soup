#ifndef RENDERING_RENDER_SYSTEM_H_
#define RENDERING_RENDER_SYSTEM_H_

#include <functional>

#include <entt/entt.hpp>

#include "../geometry/cube.h"
#include "../event/tick-event.h"

namespace soup {
namespace rendering {

template <typename T>
using CubeCallback = std::function<
  void(const geometry::Cube&, T&)
>;

class RenderSystem {
 public:
  RenderSystem();
  void Update(const entt::registry& registry, const event::TickEvent& event);
 private:
  template <typename T>
  void ViewEachCube(const entt::registry& registry,
                    const CubeCallback<T>& callback);
  void RenderCameras(const entt::registry& registry);
};

}  // namespace rendering
}  // namespace soup

#endif  // RENDERING_RENDER_SYSTEM_H_
