#ifndef COMPONENT_RENDER_AMBIENT_LIGHT_H_
#define COMPONENT_RENDER_AMBIENT_LIGHT_H_

#include <glm/glm.hpp>

namespace soup {
namespace component {

struct RenderAmbientLight {
  glm::vec4 color;
};

}  // namespace component
}  // namespace soup

#endif  // COMPONENT_RENDER_AMBIENT_LIGHT_H_
