#include "graphics-system.h"

#include <vector>

#include "../component/render-cube-faces.h"
#include "../component/render-cube-edges.h"
#include "../component/render-camera.h"
#include "../component/render-ambient-light.h"
#include "../component/render-diffuse-light.h"
#include "../component/render-viewport.h"

namespace soup {
namespace rendering {

GraphicsSystem::GraphicsSystem(const GraphicsEngine& graphics) :
  graphics_engine_(graphics) {}

void GraphicsSystem::Update(const entt::registry& registry,
                            const event::TickEvent& event) {
  graphics_engine_.SetupScene();
  RenderAmbientLights(registry);
  RenderDiffuseLights(registry);
  RenderCameras(registry);
  RenderCubeFaces(registry);
  RenderCubeEdges(registry);
  RenderViewports(registry);
  graphics_engine_.TearDownScene();
}

void GraphicsSystem::Init() {
  graphics_engine_.Init();
}

void GraphicsSystem::RenderAmbientLights(const entt::registry& registry) {
  const_cast<entt::registry&>(registry).view<
    component::RenderAmbientLight
  >().each([this] (auto& ambient_light) {
    graphics_engine_.RenderAmbientLight(ambient_light.color);
  });
}

void GraphicsSystem::RenderDiffuseLights(const entt::registry& registry) {
  const_cast<entt::registry&>(registry).view<
    component::RenderDiffuseLight
  >().each([this] (auto& diffuse_light) {
    graphics_engine_.RenderDiffuseLight(diffuse_light.color,
                                        diffuse_light.position);
  });
}

void GraphicsSystem::RenderCameras(const entt::registry& registry) {
  const_cast<entt::registry&>(registry).view<
    component::RenderCamera
  >().each([this] (auto& camera) {
    graphics_engine_.PlaceCamera(camera);
  });
}

void GraphicsSystem::RenderCubeFaces(const entt::registry& registry) {
  std::vector<geometry::Quad> quads;
  const_cast<entt::registry&>(registry).view<
    component::RenderCubeFaces
  >().each([&quads] (auto& faces) {
    quads.insert(quads.end(),
                 faces.faces,
                 faces.faces + sizeof(faces.faces) / sizeof(*faces.faces));
  });
  graphics_engine_.DrawQuads(quads);
}

void GraphicsSystem::RenderCubeEdges(const entt::registry& registry) {
  std::vector<geometry::Line> lines;
  const_cast<entt::registry&>(registry).view<
    component::RenderCubeEdges
  >().each([&lines] (auto& edges) {
    lines.insert(lines.end(),
                 edges.edges,
                 edges.edges + sizeof(edges.edges) / sizeof(*edges.edges));
  });
  graphics_engine_.DrawLines(lines);
}

void GraphicsSystem::RenderViewports(const entt::registry& registry) {
  const_cast<entt::registry&>(registry).view<
    component::RenderViewport
  >().each([this] (auto& viewport) {
    graphics_engine_.RenderViewport(viewport.width, viewport.height);
  });
}
}  // namespace rendering
}  // namespace soup
