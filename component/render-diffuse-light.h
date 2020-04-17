#ifndef COMPONENT_RENDER_DIFFUSE_LIGHT_H_
#define COMPONENT_RENDER_DIFFUSE_LIGHT_H_

#include <glm/glm.hpp>

namespace soup {
namespace component {

struct RenderDiffuseLight {
  glm::vec4 color;
  glm::vec4 position;
};

}  // namespace component
}  // namespace soup

#endif  // COMPONENT_RENDER_DIFFUSE_LIGHT_H_
