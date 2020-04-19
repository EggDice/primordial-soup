#ifndef RENDERING_GRAPHICS_ENGINE_H_
#define RENDERING_GRAPHICS_ENGINE_H_

#include <vector>

#include "../component/window.h"
#include "../geometry/quad.h"
#include "../geometry/line.h"
#include "../geometry/transform.h"

namespace soup {
namespace rendering {

class GraphicsEngine {
 public:
  virtual ~GraphicsEngine() {}
  virtual void Init() const = 0;
  virtual void SetupScene() const = 0;
  virtual void TearDownScene() const = 0;
  virtual void DrawQuads(const std::vector<geometry::Quad>& quads) const = 0;
  virtual void DrawLines(const std::vector<geometry::Line>& lines) const = 0;
  virtual void PlaceCamera(const geometry::Transform& t) const = 0;
  virtual void RenderAmbientLight(const glm::vec4& color) const = 0;
  virtual void RenderDiffuseLight(const glm::vec4& color,
                                  const glm::vec4& position) const = 0;
  virtual void RenderViewport(int width, int height) const = 0;
};

}  // namespace rendering
}  // namespace soup

#endif  // RENDERING_GRAPHICS_ENGINE_H_
