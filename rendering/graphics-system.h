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
  void Update(entt::registry& registry, const event::TickEvent& event); // NOLINT
  void Init();
 private:
  const GraphicsEngine& graphics_engine_;
  void RenderAmbientLights(entt::registry& registry); // NOLINT
  void RenderDiffuseLights(entt::registry& registry); // NOLINT
  void RenderCameras(entt::registry& registry); // NOLINT
  void RenderCubeFaces(entt::registry& registry); // NOLINT
  void RenderCubeEdges(entt::registry& registry); // NOLINT
  void RenderViewports(entt::registry& registry); // NOLINT
};

}  // namespace rendering
}  // namespace soup

#endif  // RENDERING_GRAPHICS_SYSTEM_H_
