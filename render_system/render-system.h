#ifndef RENDER_SYSTEM_RENDER_SYSTEM_H_
#define RENDER_SYSTEM_RENDER_SYSTEM_H_

#include <entt/entt.hpp>

#include "graphics.h"

namespace soup {
namespace render_system {

class RenderSystem {
 public:
  explicit RenderSystem(const Graphics& graphics);
  void Update(const entt::registry& registry, uint64_t delta_time);
 private:
  const Graphics& graphics_;
};

}  // namespace render_system
}  // namespace soup

#endif  // RENDER_SYSTEM_RENDER_SYSTEM_H_
