#ifndef WINDOW_WINDOW_UTILITY_H_
#define WINDOW_WINDOW_UTILITY_H_

#include "../component/window.h"
#include "../component/render-viewport.h"

namespace soup {
namespace window {

class WindowUtility {
 public:
  virtual ~WindowUtility() {}
  virtual void Init(int * argcp,
                    char **argv,
                    const component::RenderViewport& viewport,
                    const component::Window& window) const = 0;
};

}  // namespace window
}  // namespace soup

#endif  // WINDOW_WINDOW_UTILITY_H_
