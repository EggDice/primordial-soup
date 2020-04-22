#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>

#include "render-system.h"
#include <entt/entt.hpp>
#include "../component/position.h"
#include "../component/radius.h"
#include "../component/rotation.h"
#include "../component/color.h"
#include "../component/render-cube-faces.h"
#include "../component/render-cube-edges.h"
#include "../component/render-camera.h"
#include "../event/tick-event.h"

namespace {

namespace r = soup::rendering;
namespace c = soup::component;
namespace e = soup::event;

using ::testing::_;
using ::testing::SizeIs;

TEST(RenderSystem, RenderFaces) {
  auto render_system = r::RenderSystem{};
  auto registry = entt::registry{};
  auto entity = registry.create();
  registry.assign<c::Position>(entity, glm::vec3(0.0f, 0.0f, 0.0f));
  registry.assign<c::Radius>(entity, 1.0f);
  registry.assign<c::Color>(entity, glm::vec3(1.0f, 1.0f, 1.0f));
  registry.assign<c::RenderCubeFaces>(entity, c::RenderCubeFaces{});

  render_system.Update(registry, e::TickEvent{e::Timer::Now()});

  auto faces = registry.get<c::RenderCubeFaces>(entity);

  EXPECT_EQ(faces.faces[0].color, glm::vec3(1.0f, 1.0f, 1.0f));
}

TEST(RenderSystem, RenderEdges) {
  auto render_system = r::RenderSystem{};
  auto registry = entt::registry{};
  auto entity = registry.create();
  registry.assign<c::Position>(entity, glm::vec3(0.0f, 0.0f, 0.0f));
  registry.assign<c::Radius>(entity, 1.0f);
  registry.assign<c::Color>(entity, glm::vec3(1.0f, 1.0f, 1.0f));
  registry.assign<c::RenderCubeEdges>(entity, c::RenderCubeEdges{});

  render_system.Update(registry, e::TickEvent{e::Timer::Now()});

  auto edges = registry.get<c::RenderCubeEdges>(entity);

  EXPECT_EQ(edges.edges[0].color, glm::vec3(1.0f, 1.0f, 1.0f));
}

TEST(RenderSystem, RenderCamera) {
  auto render_system = r::RenderSystem{};
  auto registry = entt::registry{};
  auto entity = registry.create();
  registry.assign<c::Position>(entity, glm::vec3(1.0f, 1.0f, 80.0f));
  registry.assign<c::Rotation>(entity, c::Rotation{45.0f, 45.0f});
  registry.assign<c::RenderCamera>(entity, c::RenderCamera{});

  render_system.Update(registry, e::TickEvent{e::Timer::Now()});

  auto camera = registry.get<c::RenderCamera>(entity);

  EXPECT_EQ(camera.translate, glm::vec3(-1.0f, -1.0f, -80.0f));
  EXPECT_EQ(camera.rotate_x, glm::vec4(45.0f, 1.0f, 0.0f, 0.0f));
  EXPECT_EQ(camera.rotate_y, glm::vec4(45.0f, 0.0f, 1.0f, 0.0f));
}

}  // namespace

