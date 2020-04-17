#ifndef RENDERING_OPENGL_GRAPHICS_ENGINE_H_
#define RENDERING_OPENGL_GRAPHICS_ENGINE_H_

#include <vector>

#include "graphics-engine.h"
#include "../geometry/quad.h"
#include "../geometry/line.h"

namespace soup {
namespace rendering {

class OpenGlGraphicsEngine : public GraphicsEngine {
 public:
  void Init() const;
  void SetupScene() const;
  void TearDownScene() const;
  void DrawQuads(const std::vector<geometry::Quad>& quad) const;
  void DrawLines(const std::vector<geometry::Line>& line) const;
  void PlaceCamera(const geometry::Transform& transfprm) const;
  void RenderAmbientLight(const glm::vec4& color) const;
  void RenderDiffuseLight(const glm::vec4& color,
                          const glm::vec4& position) const;
};

}  // namespace rendering
}  // namespace soup

#endif  // RENDERING_OPENGL_GRAPHICS_ENGINE_H_
