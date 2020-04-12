#ifndef RENDER_SYSTEM_GRAPHICS_ENGINE_H_
#define RENDER_SYSTEM_GRAPHICS_ENGINE_H_

#include <vector>

#include "../geometry/quad.h"
#include "../geometry/line.h"

namespace soup {
namespace render_system {

class GraphicsEngine {
 public:
  virtual ~GraphicsEngine() {}
  virtual void Init() = 0;
  virtual void SetupScene() = 0;
  virtual void TearDownScene() = 0;
  virtual void DrawQuads(const std::vector<geometry::Quad>& quads) const = 0;
  virtual void DrawLines(const std::vector<geometry::Line>& lines) const = 0;
};

}  // namespace render_system
}  // namespace soup

#endif  // RENDER_SYSTEM_GRAPHICS_ENGINE_H_
