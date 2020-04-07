#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>

#include "render-system.h"
#include <entt/entt.hpp>
#include "../component/position.h"
#include "../component/radius.h"
#include "../component/color.h"
#include "../component/render.h"

namespace rs = soup::render_system;
namespace c = soup::component;

class MockGraphics : public rs::Graphics {
 public:
  MOCK_METHOD(void, Init, (), (override));
  MOCK_METHOD(void, SetupScene, (), (override));
  MOCK_METHOD(void, TearDownScene, (), (override));
  MOCK_METHOD(void, DrawQuads, (const std::vector<rs::Quad>& quads), (const));
  MOCK_METHOD(void, DrawLines, (const std::vector<rs::Line>& lines), (const));
};

namespace {

using ::testing::_;
using ::testing::SizeIs;

TEST(RenderSystem, CallDrawFunctions) {
  entt::registry registry;
  MockGraphics graphics = MockGraphics();

  rs::RenderSystem render_system(graphics);

  EXPECT_CALL(graphics, DrawQuads(_))
    .Times(1);

  EXPECT_CALL(graphics, DrawLines(_))
    .Times(1);

  render_system.Update(registry, 25);
}


TEST(RenderSystem, DrawQuads) {
  entt::registry registry;
  auto entity = registry.create();
  registry.assign<c::Position>(entity, glm::vec3(0.0f, 0.0f, 0.0f));
  registry.assign<c::Radius>(entity, 1.0f);
  registry.assign<c::Color>(entity, glm::vec3(1.0f, 1.0f, 1.0f));
  registry.assign<c::Render>(entity, c::FACE_RENDER);
  MockGraphics graphics = MockGraphics();

  rs::RenderSystem render_system(graphics);

  EXPECT_CALL(graphics, DrawQuads(SizeIs(6)))
    .Times(1);

  render_system.Update(registry, 25);
}

TEST(RenderSystem, DrawLines) {
  entt::registry registry;
  auto entity = registry.create();
  registry.assign<c::Position>(entity, glm::vec3(0.0f, 0.0f, 0.0f));
  registry.assign<c::Radius>(entity, 1.0f);
  registry.assign<c::Color>(entity, glm::vec3(1.0f, 1.0f, 1.0f));
  registry.assign<c::Render>(entity, c::EDGE_RENDER);
  MockGraphics graphics = MockGraphics();

  rs::RenderSystem render_system(graphics);

  EXPECT_CALL(graphics, DrawLines(SizeIs(12)))
    .Times(1);

  render_system.Update(registry, 25);
}
}  // namespace
