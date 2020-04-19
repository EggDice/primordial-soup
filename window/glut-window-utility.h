#ifndef WINDOW_GLUT_WINDOW_UTILITY_H_
#define WINDOW_GLUT_WINDOW_UTILITY_H_

#include "window-utility.h"

namespace soup {
namespace window {

class GlutWindowUtility : public WindowUtility {
 public:
  void Init(int * argcp,
            char **argv,
            const component::RenderViewport& viewport,
            const component::Window& window) const;
};

}  // namespace window
}  // namespace soup

#endif  // WINDOW_GLUT_WINDOW_UTILITY_H_
