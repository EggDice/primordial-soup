#include "graphics-system.h"

#include <vector>

#include "../component/render-cube-faces.h"
#include "../component/render-cube-edges.h"
#include "../component/render-camera.h"
#include "../component/render-ambient-light.h"
#include "../component/render-diffuse-light.h"
#include "../component/is-updated.h"

namespace soup {
namespace rendering {

GraphicsSystem::GraphicsSystem(const GraphicsEngine& graphics) :
  graphics_engine_(graphics) {}

void GraphicsSystem::Update(const entt::registry& registry,
                            uint64_t delta_time) {
  graphics_engine_.SetupScene();

  const_cast<entt::registry&>(registry).view<
    component::RenderAmbientLight
  >().each([this] (auto& ambient_light) {
    graphics_engine_.RenderAmbientLight(ambient_light.color);
  });

  const_cast<entt::registry&>(registry).view<
    component::RenderDiffuseLight
  >().each([this] (auto& diffuse_light) {
    graphics_engine_.RenderDiffuseLight(diffuse_light.color,
                                        diffuse_light.position);
  });

  const_cast<entt::registry&>(registry).view<
    component::RenderCamera
  >().each([this] (auto& camera) {
    graphics_engine_.PlaceCamera(camera);
  });

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

  graphics_engine_.TearDownScene();
}

void GraphicsSystem::Init(const entt::registry& registry,
                          int* argcp,
                          char ** argv) {
  const_cast<entt::registry&>(registry).view<
    component::Window,
    component::IsUpdated
  >().each([&argcp, &argv, this] (auto& window, auto& is_updated) {
    graphics_engine_.Init(argcp, argv, window);
    is_updated.is_updated = false;
  });
}

}  // namespace rendering
}  // namespace soup
