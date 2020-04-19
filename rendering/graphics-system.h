#ifndef RENDERING_GRAPHICS_SYSTEM_H_
#define RENDERING_GRAPHICS_SYSTEM_H_

#include <entt/entt.hpp>

#include "graphics-engine.h"
#include "../component/render-cube-faces.h"
#include "../event/tick-event.h"

namespace soup {
namespace rendering {

class GraphicsSystem {
 public:
  explicit GraphicsSystem(const GraphicsEngine& graphics_engine);
  void Update(const entt::registry& registry, const event::TickEvent& event);
  void Init();
 private:
  const GraphicsEngine& graphics_engine_;
  void RenderAmbientLights(const entt::registry& registry);
  void RenderDiffuseLights(const entt::registry& registry);
  void RenderCameras(const entt::registry& registry);
  void RenderCubeFaces(const entt::registry& registry);
  void RenderCubeEdges(const entt::registry& registry);
  void RenderViewports(const entt::registry& registry);
};

}  // namespace rendering
}  // namespace soup

#endif  // RENDERING_GRAPHICS_SYSTEM_H_
