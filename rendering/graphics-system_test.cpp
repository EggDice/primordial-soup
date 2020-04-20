#include <gtest/gtest.h>

#include "graphics-system.h"
#include "mock-graphics-engine.h"
#include <entt/entt.hpp>
#include "../component/render-cube-faces.h"
#include "../component/render-cube-edges.h"
#include "../component/render-camera.h"
#include "../component/render-ambient-light.h"
#include "../component/render-diffuse-light.h"
#include "../component/render-viewport.h"

namespace {
namespace r = soup::rendering;
namespace c = soup::component;
namespace g = soup::geometry;
namespace e = soup::event;

using ::testing::SizeIs;
using ::testing::NiceMock;

TEST(GraphicsSystem, DrawQuads) {
  auto graphics_engine = NiceMock<r::MockGraphicsEngine>();
  auto graphics_system = r::GraphicsSystem(graphics_engine);
  auto registry = entt::registry{};
  auto entity = registry.create();
  registry.assign<c::RenderCubeFaces>(entity, c::RenderCubeFaces{});

  EXPECT_CALL(graphics_engine, DrawQuads(SizeIs(6)))
    .Times(1);

  graphics_system.Update(registry, e::TickEvent{e::Timer::Now()});
}

TEST(RenderSystem, DrawLines) {
  auto graphics_engine = NiceMock<r::MockGraphicsEngine>();
  auto graphics_system = r::GraphicsSystem(graphics_engine);
  auto registry = entt::registry{};
  auto entity = registry.create();
  registry.assign<c::RenderCubeEdges>(entity, c::RenderCubeEdges());

  EXPECT_CALL(graphics_engine, DrawLines(SizeIs(12)))
    .Times(1);

  graphics_system.Update(registry, e::TickEvent{e::Timer::Now()});
}

TEST(RenderSystem, PlaceCamera) {
  auto graphics_engine = NiceMock<r::MockGraphicsEngine>();
  auto graphics_system = r::GraphicsSystem(graphics_engine);
  auto registry = entt::registry{};
  auto entity = registry.create();
  c::RenderCamera camera = c::RenderCamera();
  registry.assign<c::RenderCamera>(entity, camera);

  EXPECT_CALL(graphics_engine, PlaceCamera(camera))
    .Times(1);

  graphics_system.Update(registry, e::TickEvent{e::Timer::Now()});
}

TEST(RenderSystem, RenderAmbientLight) {
  auto graphics_engine = NiceMock<r::MockGraphicsEngine>();
  auto graphics_system = r::GraphicsSystem(graphics_engine);
  auto registry = entt::registry{};
  auto entity = registry.create();
  auto ambient_light = c::RenderAmbientLight{};
  registry.assign<c::RenderAmbientLight>(entity, ambient_light);

  EXPECT_CALL(graphics_engine, RenderAmbientLight(ambient_light.color))
    .Times(1);

  graphics_system.Update(registry, e::TickEvent{e::Timer::Now()});
}

TEST(RenderSystem, RenderDiffuseLight) {
  auto graphics_engine = NiceMock<r::MockGraphicsEngine>();
  auto graphics_system = r::GraphicsSystem(graphics_engine);
  auto registry = entt::registry{};
  auto entity = registry.create();
  auto diffuse_light = c::RenderDiffuseLight{};
  registry.assign<c::RenderDiffuseLight>(entity, diffuse_light);

  EXPECT_CALL(graphics_engine, RenderDiffuseLight(diffuse_light.color,
                                                  diffuse_light.position))
    .Times(1);

  graphics_system.Update(registry, e::TickEvent{e::Timer::Now()});
}

TEST(RenderSystem, SetupAndTearDownScene) {
  auto graphics_engine = NiceMock<r::MockGraphicsEngine>();
  auto graphics_system = r::GraphicsSystem(graphics_engine);
  auto registry = entt::registry{};

  EXPECT_CALL(graphics_engine, SetupScene())
    .Times(1);

  EXPECT_CALL(graphics_engine, TearDownScene())
    .Times(1);

  graphics_system.Update(registry, e::TickEvent{e::Timer::Now()});
}

TEST(RenderSystem, Init) {
  auto graphics_engine = NiceMock<r::MockGraphicsEngine>();
  auto graphics_system = r::GraphicsSystem(graphics_engine);

  EXPECT_CALL(graphics_engine, Init())
    .Times(1);

  graphics_system.Init();
}

TEST(RenderSystem, RenderViewport) {
  auto graphics_engine = NiceMock<r::MockGraphicsEngine>();
  auto graphics_system = r::GraphicsSystem(graphics_engine);
  auto registry = entt::registry{};
  auto entity = registry.create();
  auto viewport = c::RenderViewport{600, 400};
  registry.assign<c::RenderViewport>(entity, viewport);

  EXPECT_CALL(graphics_engine, RenderViewport(600, 400))
    .Times(1);

  graphics_system.Update(registry, e::TickEvent{e::Timer::Now()});
}

}  // namespace
