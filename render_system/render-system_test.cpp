#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>

#include "render-system.h"
#include <entt/entt.hpp>
#include "../component/position.h"
#include "../component/radius.h"
#include "../component/color.h"
#include "../component/render-cube-faces.h"
#include "../component/render-cube-edges.h"

namespace rs = soup::render_system;
namespace c = soup::component;

namespace {

using ::testing::_;
using ::testing::SizeIs;

TEST(RenderSystem, RenderFaces) {
  rs::RenderSystem render_system{};
  entt::registry registry;
  auto entity = registry.create();
  registry.assign<c::Position>(entity, glm::vec3(0.0f, 0.0f, 0.0f));
  registry.assign<c::Radius>(entity, 1.0f);
  registry.assign<c::Color>(entity, glm::vec3(1.0f, 1.0f, 1.0f));
  registry.assign<c::RenderCubeFaces>(entity, c::RenderCubeFaces{});

  render_system.Update(registry, 25);

  auto faces = registry.get<c::RenderCubeFaces>(entity);

  EXPECT_EQ(faces.faces[0].color, glm::vec3(1.0f, 1.0f, 1.0f));
}

TEST(RenderSystem, RenderEdges) {
  rs::RenderSystem render_system{};
  entt::registry registry;
  auto entity = registry.create();
  registry.assign<c::Position>(entity, glm::vec3(0.0f, 0.0f, 0.0f));
  registry.assign<c::Radius>(entity, 1.0f);
  registry.assign<c::Color>(entity, glm::vec3(1.0f, 1.0f, 1.0f));
  registry.assign<c::RenderCubeEdges>(entity, c::RenderCubeEdges{});

  render_system.Update(registry, 25);

  auto edges = registry.get<c::RenderCubeEdges>(entity);

  EXPECT_EQ(edges.edges[0].color, glm::vec3(1.0f, 1.0f, 1.0f));
}

}  // namespace

