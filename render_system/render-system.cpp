#include "render-system.h"

#include <vector>

#include "cube.h"
#include "../component/position.h"
#include "../component/radius.h"
#include "../component/color.h"
#include "../component/render.h"

namespace soup {
namespace render_system {

RenderSystem::RenderSystem(const Graphics& graphics) : graphics_(graphics) {}

void RenderSystem::Update(const entt::registry& registry, uint64_t delta_time) {
  auto quads = RenderBuffer<Quad>(1);
  auto lines = RenderBuffer<Line>(1);

  ViewEachCube(registry, [&] (
    auto& cube,
    auto& render) {
      if (render.render_type == component::FACE_RENDER) {
        quads.AddCube(cube);
      }
      if (render.render_type == component::EDGE_RENDER) {
        lines.AddCube(cube);
      }
  });
  quads.Render();
  lines.Render();

  graphics_.DrawQuads(quads.GetBuffer());
  graphics_.DrawLines(lines.GetBuffer());
}

void RenderSystem::ViewEachCube(const entt::registry& registry,
                                const CubeCallback& callback) {
  const_cast<entt::registry&>(registry).view<
    component::Position,
    component::Radius,
    component::Color,
    component::Render
  >().each([&callback] (
    auto& postition,
    auto& radius,
    auto& color,
    auto& render) {
      const Cube cube(postition.position, radius.radius, color.color);
      callback(cube, render);
  });
}
}  // namespace render_system
}  // namespace soup
