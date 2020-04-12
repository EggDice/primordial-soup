#ifndef RENDER_SYSTEM_OPENGL_GRAPHICS_ENGINE_H_
#define RENDER_SYSTEM_OPENGL_GRAPHICS_ENGINE_H_

#include <vector>

#include "graphics-engine.h"
#include "../geometry/quad.h"
#include "../geometry/line.h"

namespace soup {
namespace render_system {

class OpenGlGraphicsEngine : public GraphicsEngine {
 public:
  void Init();
  void SetupScene();
  void TearDownScene();
  void DrawQuads(const std::vector<geometry::Quad>& quad) const;
  void DrawLines(const std::vector<geometry::Line>& line) const;
};

}  // namespace render_system
}  // namespace soup

#endif  // RENDER_SYSTEM_OPENGL_GRAPHICS_ENGINE_H_
