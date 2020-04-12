#include "render-system.h"

#include <vector>

#include "../component/position.h"
#include "../component/radius.h"
#include "../component/color.h"
#include "../component/render-cube-faces.h"
#include "../component/render-cube-edges.h"

namespace soup {
namespace render_system {

RenderSystem::RenderSystem() {}

void RenderSystem::Update(const entt::registry& registry, uint64_t delta_time) {
  ViewEachCube<component::RenderCubeFaces>(registry, [](const auto& cube,
                                                        auto& render) {
    render = cube.GetFaces();
  });
  ViewEachCube<component::RenderCubeEdges>(registry, [](const auto& cube,
                                                        auto& render) {
    render = cube.GetEdges();
  });
}

template <typename T>
void RenderSystem::ViewEachCube(const entt::registry& registry,
                                const CubeCallback<T>& callback
) {
  const_cast<entt::registry&>(registry).view<
    component::Position,
    component::Radius,
    component::Color,
    T
  >().each([&callback] (
    auto& postition,
    auto& radius,
    auto& color,
    auto& render) {
      callback(
        geometry::Cube{postition.position, radius.radius, color.color},
        render);
  });
}

}  // namespace render_system
}  // namespace soup
