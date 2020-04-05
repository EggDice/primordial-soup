#ifndef RENDER_SYSTEM_GRAPHICS_H_
#define RENDER_SYSTEM_GRAPHICS_H_

#include <vector>

#include "quad.h"
#include "line.h"

namespace soup {
namespace render_system {

class Graphics {
 public:
  virtual ~Graphics() {}
  virtual void Init() = 0;
  virtual void SetupScene() = 0;
  virtual void TearDownScene() = 0;
  virtual void DrawQuads(const std::vector<Quad>& quads) const = 0;
  virtual void DrawLines(const std::vector<Line>& lines) const = 0;
};

}  // namespace render_system
}  // namespace soup

#endif  // RENDER_SYSTEM_GRAPHICS_H_
