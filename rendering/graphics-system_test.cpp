#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>

#include "graphics-system.h"
#include <entt/entt.hpp>
#include "../component/render-cube-faces.h"
#include "../component/render-cube-edges.h"
#include "../component/render-camera.h"
#include "../component/render-ambient-light.h"
#include "../component/render-diffuse-light.h"

namespace r = soup::rendering;
namespace c = soup::component;
namespace g = soup::geometry;

class MockGraphicsEngine : public r::GraphicsEngine {
 public:
  MOCK_METHOD(void, Init, (), (const));
  MOCK_METHOD(void, SetupScene, (), (const));
  MOCK_METHOD(void, TearDownScene, (), (const));
  MOCK_METHOD(void, DrawQuads, (const std::vector<g::Quad>& quads), (const));
  MOCK_METHOD(void, DrawLines, (const std::vector<g::Line>& lines), (const));
  MOCK_METHOD(void, PlaceCamera, (const g::Transform& t), (const));
  MOCK_METHOD(void, RenderAmbientLight, (const glm::vec4& color), (const));
  MOCK_METHOD(void,
              RenderDiffuseLight,
              (const glm::vec4& color, const glm::vec4& position),
              (const));
};

namespace {

using ::testing::_;
using ::testing::SizeIs;

TEST(GraphicsSystem, DrawQuads) {
  MockGraphicsEngine graphics_engine = MockGraphicsEngine();
  r::GraphicsSystem graphics_system(graphics_engine);

  entt::registry registry;
  auto entity = registry.create();
  registry.assign<c::RenderCubeFaces>(entity, c::RenderCubeFaces{});

  EXPECT_CALL(graphics_engine, DrawQuads(SizeIs(6)))
    .Times(1);

  graphics_system.Update(registry, 25);
}

TEST(RenderSystem, DrawLines) {
  MockGraphicsEngine graphics_engine = MockGraphicsEngine();
  r::GraphicsSystem graphics_system(graphics_engine);

  entt::registry registry;
  auto entity = registry.create();
  registry.assign<c::RenderCubeEdges>(entity, c::RenderCubeEdges());

  EXPECT_CALL(graphics_engine, DrawLines(SizeIs(12)))
    .Times(1);

  graphics_system.Update(registry, 25);
}

TEST(RenderSystem, PlaceCamera) {
  MockGraphicsEngine graphics_engine = MockGraphicsEngine();
  r::GraphicsSystem graphics_system(graphics_engine);

  entt::registry registry;
  auto entity = registry.create();
  c::RenderCamera camera = c::RenderCamera();
  registry.assign<c::RenderCamera>(entity, camera);

  EXPECT_CALL(graphics_engine, PlaceCamera(camera))
    .Times(1);

  graphics_system.Update(registry, 25);
}

TEST(RenderSystem, RenderAmbientLight) {
  MockGraphicsEngine graphics_engine = MockGraphicsEngine();
  r::GraphicsSystem graphics_system(graphics_engine);

  entt::registry registry;
  auto entity = registry.create();
  c::RenderAmbientLight ambient_light = c::RenderAmbientLight{};
  registry.assign<c::RenderAmbientLight>(entity, ambient_light);

  EXPECT_CALL(graphics_engine, RenderAmbientLight(ambient_light.color))
    .Times(1);

  graphics_system.Update(registry, 25);
}

TEST(RenderSystem, RenderDiffuseLight) {
  MockGraphicsEngine graphics_engine = MockGraphicsEngine();
  r::GraphicsSystem graphics_system(graphics_engine);

  entt::registry registry;
  auto entity = registry.create();
  c::RenderDiffuseLight diffuse_light = c::RenderDiffuseLight{};
  registry.assign<c::RenderDiffuseLight>(entity, diffuse_light);

  EXPECT_CALL(graphics_engine, RenderDiffuseLight(diffuse_light.color,
                                                  diffuse_light.position))
    .Times(1);

  graphics_system.Update(registry, 25);
}

TEST(RenderSystem, SetupAndTearDownScene) {
  MockGraphicsEngine graphics_engine = MockGraphicsEngine();
  r::GraphicsSystem graphics_system(graphics_engine);

  entt::registry registry;

  EXPECT_CALL(graphics_engine, SetupScene())
    .Times(1);

  EXPECT_CALL(graphics_engine, TearDownScene())
    .Times(1);

  graphics_system.Update(registry, 25);
}

}  // namespace
