#ifndef COMPONENT_RENDER_H_
#define COMPONENT_RENDER_H_

namespace soup {
namespace component {

enum RenderType {
  FACE_RENDER,
  EDGE_RENDER
};

struct Render {
  RenderType render_type;
};

}  // namespace component
}  // namespace soup

#endif  // COMPONENT_RENDER_H_
