#ifndef RENDER_SYSTEM_GRAPHICS_SYSTEM_H_
#define RENDER_SYSTEM_GRAPHICS_SYSTEM_H_

#include <functional>

#include <entt/entt.hpp>

#include "graphics-engine.h"
#include "../component/render-cube-faces.h"

namespace soup {
namespace render_system {

class GraphicsSystem {
 public:
  explicit GraphicsSystem(const GraphicsEngine& graphics_engine);
  void Update(const entt::registry& registry, uint64_t delta_time);
 private:
  const GraphicsEngine& graphics_engine_;
};

}  // namespace render_system
}  // namespace soup

#endif  // RENDER_SYSTEM_GRAPHICS_SYSTEM_H_
