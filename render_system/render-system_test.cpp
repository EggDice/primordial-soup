#include "render-system.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <entt/entt.hpp>

#include "graphics.h"
#include "../component/position.h"
#include "../component/color.h"
#include "../component/render.h"

namespace rs = soup::render_system;
namespace c = soup::component;

class MockGraphics : rs::Graphics {
 public:
  MOCK_METHOD(void, Init, (), (override));
  MOCK_METHOD(void, SetupScene, (), (override));
  MOCK_METHOD(void, TearDownScene, (), (override));
  MOCK_METHOD(void, DrawQuad, (rs::Quad quad), (override));
  MOCK_METHOD(void, DrawLine, (rs::Line line), (override));
};

namespace {
TEST(RenderSystem, UpdateEntities) {
  entt::registry registry;
  auto entity = registry.create();
  registry.assign<c::Position>(entity, glm::vec3(0.0f, 0.0f, 0.0f));
  registry.assign<c::Color>(entity, glm::vec3(1.0f, 1.0f, 1.0f));
  registry.assign<c::Render>(entity, c::FACE_RENDER);
  MockGraphics graphics = MockGraphics();
}
}  // namespace
