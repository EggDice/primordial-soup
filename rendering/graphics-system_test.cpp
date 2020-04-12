#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>

#include "graphics-system.h"
#include <entt/entt.hpp>
#include "../component/render-cube-faces.h"
#include "../component/render-cube-edges.h"

namespace r = soup::rendering;
namespace c = soup::component;
namespace g = soup::geometry;

class MockGraphicsEngine : public r::GraphicsEngine {
 public:
  MOCK_METHOD(void, Init, (), (override));
  MOCK_METHOD(void, SetupScene, (), (override));
  MOCK_METHOD(void, TearDownScene, (), (override));
  MOCK_METHOD(void, DrawQuads, (const std::vector<g::Quad>& quads), (const));
  MOCK_METHOD(void, DrawLines, (const std::vector<g::Line>& lines), (const));
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

}  // namespace
