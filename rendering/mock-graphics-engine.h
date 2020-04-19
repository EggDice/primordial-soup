#ifndef RENDERING_MOCK_GRAPHICS_ENGINE_H_
#define RENDERING_MOCK_GRAPHICS_ENGINE_H_

#include <gmock/gmock.h>
#include <vector>

#include "graphics-engine.h"

namespace soup {
namespace rendering {

class MockGraphicsEngine : public GraphicsEngine {
 public:
  MOCK_METHOD(void, Init, (), (const));
  MOCK_METHOD(void, SetupScene, (), (const));
  MOCK_METHOD(void, TearDownScene, (), (const));
  MOCK_METHOD(void, DrawQuads, (const std::vector<geometry::Quad>& quads),
                               (const));
  MOCK_METHOD(void, DrawLines, (const std::vector<geometry::Line>& lines),
                               (const));
  MOCK_METHOD(void, PlaceCamera, (const geometry::Transform& t), (const));
  MOCK_METHOD(void, RenderAmbientLight, (const glm::vec4& color), (const));
  MOCK_METHOD(void,
              RenderDiffuseLight,
              (const glm::vec4& color, const glm::vec4& position),
              (const));
  MOCK_METHOD(void, RenderViewport, (int width, int height), (const));
};

}  // namespace rendering
}  // namespace soup

#endif  // RENDERING_MOCK_GRAPHICS_ENGINE_H_
