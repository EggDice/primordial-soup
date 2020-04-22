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
  void Update(entt::registry& registry, const event::TickEvent& event); // NOLINT
 private:
  template <typename T>
  void ViewEachCube(entt::registry& registry, // NOLINT
                    const CubeCallback<T>& callback);
  void RenderCameras(entt::registry& registry); // NOLINT
};

}  // namespace rendering
}  // namespace soup

#endif  // RENDERING_RENDER_SYSTEM_H_
