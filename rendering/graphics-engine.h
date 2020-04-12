#ifndef RENDERING_GRAPHICS_ENGINE_H_
#define RENDERING_GRAPHICS_ENGINE_H_

#include <vector>

#include "../geometry/quad.h"
#include "../geometry/line.h"
#include "../geometry/transform.h"

namespace soup {
namespace rendering {

class GraphicsEngine {
 public:
  virtual ~GraphicsEngine() {}
  virtual void Init() = 0;
  virtual void SetupScene() = 0;
  virtual void TearDownScene() = 0;
  virtual void DrawQuads(const std::vector<geometry::Quad>& quads) const = 0;
  virtual void DrawLines(const std::vector<geometry::Line>& lines) const = 0;
  virtual void PlaceCamera(const geometry::Transform& t) const = 0;
};

}  // namespace rendering
}  // namespace soup

#endif  // RENDERING_GRAPHICS_ENGINE_H_
