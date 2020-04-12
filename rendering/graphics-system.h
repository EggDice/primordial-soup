#ifndef RENDERING_GRAPHICS_SYSTEM_H_
#define RENDERING_GRAPHICS_SYSTEM_H_

#include <entt/entt.hpp>

#include "graphics-engine.h"
#include "../component/render-cube-faces.h"

namespace soup {
namespace rendering {

class GraphicsSystem {
 public:
  explicit GraphicsSystem(const GraphicsEngine& graphics_engine);
  void Update(const entt::registry& registry, uint64_t delta_time);
 private:
  const GraphicsEngine& graphics_engine_;
};

}  // namespace rendering
}  // namespace soup

#endif  // RENDERING_GRAPHICS_SYSTEM_H_
