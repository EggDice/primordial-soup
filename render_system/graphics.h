#ifndef RENDER_SYSTEM_GRAPHICS_H_
#define RENDER_SYSTEM_GRAPHICS_H_

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
  virtual void DrawQuad(Quad quad) = 0;
  virtual void DrawLine(Line line) = 0;
};

}  // namespace render_system
}  // namespace soup

#endif  // RENDER_SYSTEM_GRAPHICS_H_
