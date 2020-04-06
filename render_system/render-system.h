#ifndef RENDER_SYSTEM_RENDER_SYSTEM_H_
#define RENDER_SYSTEM_RENDER_SYSTEM_H_

#include <functional>

#include <entt/entt.hpp>

#include "cube.h"
#include "graphics.h"
#include "../component/render.h"

namespace soup {
namespace render_system {

typedef std::function<void(const Cube&, const component::Render&)> CubeCallback;

class RenderSystem {
 public:
  explicit RenderSystem(const Graphics& graphics);
  void Update(const entt::registry& registry, uint64_t delta_time);
 private:
  const Graphics& graphics_;
  void ViewEachCube(
      const entt::registry& registry,
      const CubeCallback& callback);
};

}  // namespace render_system
}  // namespace soup

#endif  // RENDER_SYSTEM_RENDER_SYSTEM_H_
