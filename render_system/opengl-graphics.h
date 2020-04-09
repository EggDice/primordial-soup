#ifndef RENDER_SYSTEM_OPENGL_GRAPHICS_H_
#define RENDER_SYSTEM_OPENGL_GRAPHICS_H_

#include <vector>

#include "graphics.h"
#include "quad.h"
#include "line.h"

namespace soup {
namespace render_system {

class OpenGlGraphics : public Graphics {
 public:
  void Init();
  void SetupScene();
  void TearDownScene();
  void DrawQuads(const std::vector<Quad>& quads) const;
  void DrawLines(const std::vector<Line>& lines) const;
};

}  // namespace render_system
}  // namespace soup

#endif  // RENDER_SYSTEM_OPENGL_GRAPHICS_H_
