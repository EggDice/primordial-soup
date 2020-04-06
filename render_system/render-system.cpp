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
  auto quads = std::vector<Quad>();
  auto lines = std::vector<Line>();

  ViewEachCube(registry, [&quads] (
    auto& cube,
    auto& render) {
      auto quads_to_add = cube.GetQuads();
      quads.insert(quads.end(), quads_to_add.begin(), quads_to_add.end());
  });

  graphics_.DrawQuads(quads);
  graphics_.DrawLines(lines);
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
      callback(cube, const_cast<const component::Render&>(render));
  });
}
}  // namespace render_system
}  // namespace soup
