#ifndef RENDER_SYSTEM_RENDER_SYSTEM_H_
#define RENDER_SYSTEM_RENDER_SYSTEM_H_

#include <functional>

#include <entt/entt.hpp>

#include "../geometry/cube.h"

namespace soup {
namespace render_system {

template <typename T>
using CubeCallback = std::function<
  void(const geometry::Cube&, T&)
>;

class RenderSystem {
 public:
  RenderSystem();
  void Update(const entt::registry& registry, uint64_t delta_time);
 private:
  template <typename T>
  void ViewEachCube(
      const entt::registry& registry,
      const CubeCallback<T>& callback
);
};

}  // namespace render_system
}  // namespace soup

#endif  // RENDER_SYSTEM_RENDER_SYSTEM_H_
