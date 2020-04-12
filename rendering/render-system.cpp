#include "render-system.h"

#include "../component/position.h"
#include "../component/radius.h"
#include "../component/rotation.h"
#include "../component/color.h"
#include "../component/render-cube-faces.h"
#include "../component/render-cube-edges.h"
#include "../component/render-camera.h"

namespace soup {
namespace rendering {

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
  const_cast<entt::registry&>(registry).view<
    component::Position,
    component::Rotation,
    component::RenderCamera
  >().each([](const auto& position, const auto& rotation, auto& render) {
    render = component::RenderCamera(
      position.position,
      rotation.angle_x,
      rotation.angle_y);
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
    auto& position,
    auto& radius,
    auto& color,
    auto& render) {
      callback(
        geometry::Cube{position.position, radius.radius, color.color},
        render);
  });
}

}  // namespace rendering
}  // namespace soup
