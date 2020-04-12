#include "graphics-system.h"

#include <vector>

#include "../component/render-cube-faces.h"
#include "../component/render-cube-edges.h"

namespace soup {
namespace render_system {

GraphicsSystem::GraphicsSystem(const GraphicsEngine& graphics) :
  graphics_engine_(graphics) {}

void GraphicsSystem::Update(const entt::registry& registry,
                            uint64_t delta_time) {
  std::vector<geometry::Quad> quads;
  const_cast<entt::registry&>(registry).view<
    component::RenderCubeFaces
  >().each([&quads] (auto& faces) {
    quads.insert(quads.end(), faces.faces, faces.faces + 6);
  });
  graphics_engine_.DrawQuads(quads);

  std::vector<geometry::Line> lines;
  const_cast<entt::registry&>(registry).view<
    component::RenderCubeEdges
  >().each([&lines] (auto& edges) {
    lines.insert(lines.end(), edges.edges, edges.edges + 12);
  });
  graphics_engine_.DrawLines(lines);
}

}  // namespace render_system
}  // namespace soup
