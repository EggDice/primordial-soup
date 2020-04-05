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

  const_cast<entt::registry&>(registry).view<
    component::Position,
    component::Radius,
    component::Color,
    component::Render
  >().each([&quads] (
    auto& postition,
    auto& radius,
    auto& color,
    auto& render) {
      Cube cube(postition.position, radius.radius, color.color);
      auto quads_to_add = cube.GetQuads();
      quads.insert(quads.end(), quads_to_add.begin(), quads_to_add.end());
  });

  graphics_.DrawQuads(quads);
  graphics_.DrawLines(lines);
}
}  // namespace render_system
}  // namespace soup
